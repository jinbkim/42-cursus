import { FC, Dispatch, SetStateAction, useContext } from "react";
import { Link, RouteComponentProps, withRouter } from "react-router-dom";
import { UserInfoContext } from "../../../../Context";
import "/src/scss/content/chat/ChatContextMenu.scss";

interface chatContextMenuProps {
  x: number,
  y: number,
  myPosition: string, /* "owner" || "admin" || "normal" || "mute" || "ban" */
  targetPosition: string,
  target: string,
  closer: Dispatch<SetStateAction<{
    isOpen: boolean,
    x: number,
    y: number,
    target: string,
    targetPosition: string
  }>>
}

const ConditionalContextMenu: FC<{myPosition: string, targetPosition: string}> = ({myPosition, targetPosition}) => {
  switch (myPosition) {
    case "owner":
      return (
        <>
          <li className="chat-context-li">{targetPosition === "admin" ? "관리자 해임" : "관리자로 임명"}</li>
          <li className="chat-context-li">강퇴하기</li>
          <li className="chat-context-li">{targetPosition === "mute" ? "대화 차단 해제" : "대화 차단하기"}</li>
        </>
      );
    case "admin":
      if ((targetPosition !== "owner") && (targetPosition !== "admin")) {
        return (
          <>
            <li className="chat-context-li">강퇴하기</li>
            <li className="chat-context-li">{targetPosition === "mute" ? "대화 차단 해제" : "대화 차단하기"}</li>
          </>
        );
      }
    default:
      return <></>
  };
}

const ChatContextMenu: FC<chatContextMenuProps & RouteComponentProps> = ({match, x, y, myPosition, targetPosition, target, closer}): JSX.Element => {
  const myInfo = useContext(UserInfoContext);

  return (
    <div id="chat-context-menu" onClick={() => {
      document.getElementById("chat-room-users").style.overflowY = "auto";
      closer({
        isOpen: false,
        x: 0,
        y: 0,
        target: "",
        targetPosition: ""
      })
    }}>
      <ul id="context-menu" style={{ top: y, left: x, }}>
        <Link to={`${match.url}/profile/${target}`} style={{color: "inherit", textDecoration: "none"}}>
          <li className="chat-context-li">프로필 보기</li>
        </Link>
        {myInfo.nick !== target ? 
          <>
            <li className="chat-context-li">대전 신청</li>
            <ConditionalContextMenu myPosition={myPosition} targetPosition={targetPosition} />
          </>
          : <></>}
      </ul>
    </div>
  );
};

export default withRouter(ChatContextMenu);