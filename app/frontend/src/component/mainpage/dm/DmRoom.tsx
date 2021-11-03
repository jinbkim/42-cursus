import React, { FC, useEffect, useState, useRef, useContext, Dispatch, SetStateAction } from "react";
import { Redirect } from "react-router-dom";
import { DmInfo, UserInfoContext } from "../../../Context";
import "../../../scss/dm/DmRoom.scss";
import EasyFetch from "../../../utils/EasyFetch";
import Time from "../../../utils/Time";
import { UserInfo } from "../MainPage";

interface DMLog {
  time: string, /* e.g.) "2021-07-31T05:41:48.342Z" */
  msg: string,  /* e.g.) "반갑다" */
  from: string, /* e.g.) "me" || "hna" */
  type: string, /* e.g.) "normal" || "chat"(대화방 초대) || "game"(게임 초대) */
  id: number,   /* 초대 승낙, 거절 할 시 해당 데이터를 DB 에서 제거하기 위함 */
}

/*!
 * @author yochoi, donglee
 * @brief DmRoom 안에서 DmLog 를 보여주는 FC
 * @param[in] dmLog: DmRoom 에서 관리하는 dmLog state
 * @param[in] myInfo: 전역객체인 내 정보(내가 보낸 것과 받은 것을 구분하기 위함)
 * @param[in] setChannelId: 초대 승낙할 때 해당 channelId로 Redirect 하기 위함
 * @param[in] setDmLog: 승낙, 거절 후 초대 메세지를 지우기 위해 state 를 update 함
 */

interface DmLogListProps {
  dmLog: DMLog[],
  myInfo: UserInfo,
  setChannelId: Dispatch<SetStateAction<number>>,
  setDmLog: Dispatch<SetStateAction<DMLog[]>>,
}

const DmLogList: FC<DmLogListProps> = ({dmLog, myInfo, setChannelId, setDmLog}) => {

  /*!
   * @author donglee
   * @brief 승낙, 거절을 누르면 DmLoom 에서 초대장을 제거하고 새로 보여주기 위함
   */
  const updateDmLog = (logId: number) => {
    const updatedDmLog: DMLog[] = dmLog.filter((log) => {
      return (log.id !== logId);
    });
    setDmLog(updatedDmLog);
  };

  /*!
   * @author donglee
   * @brief - 대화방 초대를 승낙하면 해당 channelId를 이용해 redirect 함
   *        - DB 에서 해당 로그를 삭제하고 DmLog 를 업데이트함
   */
  const approveChatInvite = async (channelId: number, logId: number) => {
    const easyfetch = new EasyFetch(`${global.BE_HOST}/dm-store/oneLog?dm_log_id=${logId}`, "DELETE");
    const res = await easyfetch.fetch();

    if (!res.err_msg) {
      updateDmLog(logId);
      setChannelId(channelId);
    } else {
      alert(res.err_msg);
    }
  };

  /*!
   * @author donglee
   * @brief DB 에서 해당 로그를 삭제하고 현재 화면에서 DmLog 를 update 함
   */
  const rejectChatInvite = async (e: React.MouseEvent, logId: number) => {
    const easyfetch = new EasyFetch(`${global.BE_HOST}/dm-store/oneLog?dm_log_id=${logId}`, "DELETE");
    const res = await easyfetch.fetch();

    if (res.err_msg) {
      alert(res.err_msg);
      return ;
    }
    updateDmLog(logId);
  }

  /*!
   * @author yochoi, donglee
   * @brief 초대메세지와 normal 메세지를 나눠서 화면에 렌더링함
   */
  const printChatLog = (msg: DMLog, idx: number) => {
    const timeParser = new Time(msg.time);
    const timeFormat = timeParser.getTimeFormat();
    const hour = timeParser.getHour();
    const minute = timeParser.getMinuate();
    if (msg.type === "chat") {
      const parsedMsg = JSON.parse(msg.msg);
      
      return (
        <div key={idx} className={`dm-request-container ${msg.from === myInfo.nick ? "me" : "other"}`}>
          <div className="dm-invitation-part">
            <span className="dm-request-msg">{msg.from} 님이 {parsedMsg.chatTitle} 대화방에 초대했습니다.</span>
            <div className="dm-request-btn-container">
              <div className="dm-request-approve">
                <img
                  className="dm-reply-img"
                  src="/public/green-check.png"
                  alt="승낙"
                  onClick={() => approveChatInvite(parsedMsg.channelId, msg.id)} />
              </div>
              <div className="dm-request-reject">
                <img
                  className="dm-reply-img"
                  src="/public/red-x.png" 
                  alt="거절"
                  onClick={(e) => rejectChatInvite(e, msg.id)} />
              </div>
            </div>
          </div>
          <span className="dm-request-time">{`${timeFormat} ${hour}:${minute}`}</span>
        </div>
      );
    }

    return (
      <div key={idx}>
        <li key={idx} className={`dm-log ${msg.from === myInfo.nick ? "me" : "other"}`}>
          <span className="dm-log-msg">
            {
              /*!
                * @author yochoi
                * @brief 문자열(챗로그)에 개행이 있으면 br 태그로 줄바꿈해주는 부분
                */
              msg.msg.split('\n').map((chatlog, idx) => {
                return (<span key={idx}>{chatlog}<br /></span>);
              })
            }
          </span>
          <span className="dm-log-time">{`${timeFormat} ${hour}:${minute}`}</span>
        </li>
      </div>
    );
  }
  
  return (
    <ul className="dm-log-list">
      {dmLog.map(printChatLog)}
    </ul>
  );
}

interface DmRoomProps {
  dmInfo: DmInfo;
}

const DmRoom: FC<DmRoomProps> = ({dmInfo}): JSX.Element => {

  const [dmLog, _setDmLog] = useState<DMLog[]>([]);
  const dmLogRef = useRef(dmLog);
  const setDmLog = (x: DMLog[]) => {
    dmLogRef.current = x;
    _setDmLog(x);
  };
  const [textAreaMsg, setTextAreaMsg] = useState("");
  const [channelId, setChannelId] = useState(0);

  const myInfo = useContext(UserInfoContext);

  /*! 
   * @author yochoi
   * @brief 전송 버튼을 눌렀을 때 dmLog 를 갱신함
  */
  const sendDm = (e: React.FormEvent) => {
    e.preventDefault();
    if (textAreaMsg === "") return ;
    global.socket.emit("dm", {to: dmInfo.target, msg: textAreaMsg});
    getDmLog();
    setTextAreaMsg("");
  }

  /*!
   * @author donglee
   * @brief 초대하기를 누르면 DmRoom 컴포넌트가 열리면서 이 함수가 바로 실행됨
   *        소켓으로 데이터를 전달하여 target 에게 DM이 가도록 함
   */
  const sendRequest = () => {
    global.socket.emit("chatInvite", {
      from: dmInfo.request.from,
      target: dmInfo.target,
      chatTitle: dmInfo.request.chatTitle,
      channelId: dmInfo.request.channelId,
    });
    getDmLog();
  };

  const controlTextAreaKeyDown = (e: React.KeyboardEvent) => {
    const keyCode = e.key;

    if (keyCode === "Enter" && !e.shiftKey) {
      e.preventDefault();
      sendDm(e as React.FormEvent);
    }
  };

  const getDmLog = async () => {
    const easyfetch = new EasyFetch(`${global.BE_HOST}/dm-store?receiver_nick=${dmInfo.target}`);
    const res = await easyfetch.fetch();

    setDmLog(res);
  };

  useEffect(() => {
    getDmLog();

    if (dmInfo.request) {
      sendRequest();
    }

    const dmOn = (dm) => {
      setDmLog([{...dm}, ...dmLogRef.current]);
    };

    const chatInviteOn = (request) => {
      setDmLog([{...request}, ...dmLogRef.current]);
    };

    global.socket.on("dm", dmOn);
    global.socket.on("chatInvite", chatInviteOn);
    return (() => {
      global.socket.off("dm", dmOn);
      global.socket.off("chatInvite", chatInviteOn);
    });
  }, []);

  if (channelId) {
    return ( <Redirect push to={{
      pathname: `/mainpage/chat/${channelId}`,
      state: {isInvited: true},
    }} />);
  }
  return (
    <div className="dm-room">
      <DmLogList dmLog={dmLog} myInfo={myInfo} setChannelId={setChannelId} setDmLog={setDmLog}/>
      <form className="dm-form">
        <textarea
          className="dm-msg-textarea"
          placeholder="대화내용 입력"
          rows={4}
          cols={50}
          value={textAreaMsg}
          onChange={({target: {value}}) => setTextAreaMsg(value)}
          onKeyPress={controlTextAreaKeyDown}/>
        <button
          className="dm-msg-button"
          disabled={textAreaMsg === ""}
          onClick={sendDm}>전송</button>
      </form>
    </div>
  );
};

export default DmRoom;
