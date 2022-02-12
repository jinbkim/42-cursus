import { useEffect, useState } from 'react';
import Modal from '../modal/Modal';
import LoginTwoFactor from './LoginTwoFactor';
import "/src/scss/login/Login.scss";

const PONG_SCREEN_WIDTH = 1920;
const PONG_SCREEN_HEIGHT = 1080;
const PONG_START_POINT = { x: PONG_SCREEN_WIDTH / 2, y: PONG_SCREEN_HEIGHT / 2 };
const PONG_START_DIRECTION = { vx: 2, vy: 2 };
const PONG_BALL_RADIUS = 20;
const PONG_BAR_WIDTH = 20;
const PONG_BAR_HEIGHT = 250;

interface pongBall {
  x: number;
  y: number;
  vx: number;
  vy: number;
};

interface pongBar {
  y: number,
  direction: string
};

const BackGroundPingPongSVG = (): JSX.Element => {

  const [ballXY, setBallXY] = useState<pongBall>({...PONG_START_POINT, ...PONG_START_DIRECTION});
  const [leftBarY, setLeftBarY] = useState<pongBar>({y: PONG_SCREEN_HEIGHT / 2, direction: "up"});
  const [rightBarY, setRightBarY] = useState<pongBar>({y: PONG_SCREEN_HEIGHT / 2, direction: "down"});

  const xCollision = (x: number, r: number): boolean => {
    return ((x - r) < 0 || (x + r) > PONG_SCREEN_WIDTH);
  };

  const yCollision = (y: number, r: number): boolean => {
    return ((y - r) < 0 || (y + r) > PONG_SCREEN_HEIGHT);
  };

  const ballMovement = (ballXY: pongBall): pongBall => {
    const {x, y, vx, vy} = ballXY;
    if (xCollision(x, PONG_BALL_RADIUS)) {
      return ({x: x + (vx * -1), y: y + vy, vx: vx * -1, vy: vy});
    } else if (yCollision(y, PONG_BALL_RADIUS)) {
      return ({x: x + vx, y: y + (vy * -1), vx: vx, vy: vy * -1});
    }
    return ({x: x + vx, y: y + vy, vx: vx, vy: vy});
  }

  const barMovement = (barXY: pongBar): pongBar => {
    if ((barXY.y) < 0 || (barXY.y + PONG_BAR_HEIGHT) > PONG_SCREEN_HEIGHT) {
      return ({y: barXY.y + (barXY.direction === "up" ? 1 : -1), direction: (barXY.direction === "up" ? "down" : "up")});
    }
    if (barXY.direction === "up") {
      return ({y: barXY.y - 1, direction: "up"});
    } else if (barXY.direction === "down") {
      return ({y: barXY.y + 1, direction: "down"});
    }
  }

  useEffect(() => {
    const ballInterval = setInterval(() => {
      setBallXY(ballXY => ballMovement(ballXY));
      setLeftBarY(leftBarY => barMovement(leftBarY));
      setRightBarY(rightBarY => barMovement(rightBarY));
    }, 1);
    return (() => clearInterval(ballInterval));
  }, []);

  return (
    <svg width="100%" height="100%" viewBox="0 0 1920 1080" fill="none" xmlns="http://www.w3.org/2000/svg">
      <g id="Table">
        <rect width="100%" height="100%" stroke="white"/>
        <g id="Bar">
          <rect id="Left bar" x="50" y={leftBarY.y} width={PONG_BAR_WIDTH} height={PONG_BAR_HEIGHT} fill="white"/>
          <rect id="Right bar" x="1850" y={rightBarY.y} width={PONG_BAR_WIDTH} height={PONG_BAR_HEIGHT} fill="white"/>
        </g>
        <g id="Center">
          <circle id="Circle" cx="960" cy="540" r="99.5" fill="black" stroke="white"/>
          <line id="Line" x1="959.5" y1="1080" x2="959.5" y2="-6.10352e-05" stroke="white"/>
        </g>
        <circle id="Ball" cx={ballXY.x} cy={ballXY.y} r={PONG_BALL_RADIUS} fill="white"/>
        <g id="Logo">
          <g id="42_Logo">
            <path id="polygon5" d="M676.667 172.625H745.438V207.083H779.75V144.812H711.104L779.75 76.0208H745.438L676.667 144.812V172.625Z" fill="white"/>
            <path id="polygon7" d="M794.562 110.458L828.896 76.0208H794.562V110.458Z" fill="white"/>
            <path id="polygon9" d="M828.896 110.458L794.562 144.812V179.146H828.896V144.812L863.333 110.458V76.0208H828.896V110.458Z" fill="white"/>
            <path id="polygon11" d="M863.333 144.813L828.896 179.146H863.333V144.813Z" fill="white"/>
          </g>
          <path id="Ping Pong" d="M884.102 144.734V167H876.602V110.125H897.578C903.802 110.125 908.672 111.714 912.188 114.891C915.729 118.068 917.5 122.273 917.5 127.508C917.5 133.029 915.768 137.286 912.305 140.281C908.867 143.25 903.932 144.734 897.5 144.734H884.102ZM884.102 138.602H897.578C901.589 138.602 904.661 137.664 906.797 135.789C908.932 133.888 910 131.154 910 127.586C910 124.201 908.932 121.492 906.797 119.461C904.661 117.43 901.732 116.375 898.008 116.297H884.102V138.602ZM933.789 167H926.562V124.734H933.789V167ZM925.977 113.523C925.977 112.352 926.328 111.362 927.031 110.555C927.76 109.747 928.828 109.344 930.234 109.344C931.641 109.344 932.708 109.747 933.438 110.555C934.167 111.362 934.531 112.352 934.531 113.523C934.531 114.695 934.167 115.672 933.438 116.453C932.708 117.234 931.641 117.625 930.234 117.625C928.828 117.625 927.76 117.234 927.031 116.453C926.328 115.672 925.977 114.695 925.977 113.523ZM952.227 124.734L952.461 130.047C955.69 125.984 959.909 123.953 965.117 123.953C974.049 123.953 978.555 128.992 978.633 139.07V167H971.406V139.031C971.38 135.984 970.677 133.732 969.297 132.273C967.943 130.815 965.82 130.086 962.93 130.086C960.586 130.086 958.529 130.711 956.758 131.961C954.987 133.211 953.607 134.852 952.617 136.883V167H945.391V124.734H952.227ZM987.812 145.516C987.812 138.927 989.336 133.693 992.383 129.812C995.43 125.906 999.466 123.953 1004.49 123.953C1009.65 123.953 1013.67 125.776 1016.56 129.422L1016.91 124.734H1023.52V165.984C1023.52 171.453 1021.89 175.763 1018.63 178.914C1015.4 182.065 1011.05 183.641 1005.59 183.641C1002.54 183.641 999.557 182.99 996.641 181.688C993.724 180.385 991.497 178.602 989.961 176.336L993.711 172C996.81 175.828 1000.6 177.742 1005.08 177.742C1008.59 177.742 1011.33 176.753 1013.28 174.773C1015.26 172.794 1016.25 170.008 1016.25 166.414V162.781C1013.36 166.115 1009.41 167.781 1004.41 167.781C999.466 167.781 995.456 165.789 992.383 161.805C989.336 157.82 987.812 152.391 987.812 145.516ZM995.078 146.336C995.078 151.102 996.055 154.852 998.008 157.586C999.961 160.294 1002.7 161.648 1006.21 161.648C1010.77 161.648 1014.11 159.578 1016.25 155.438V136.141C1014.04 132.104 1010.72 130.086 1006.29 130.086C1002.77 130.086 1000.03 131.453 998.047 134.188C996.068 136.922 995.078 140.971 995.078 146.336ZM1062.93 144.734V167H1055.43V110.125H1076.41C1082.63 110.125 1087.5 111.714 1091.02 114.891C1094.56 118.068 1096.33 122.273 1096.33 127.508C1096.33 133.029 1094.6 137.286 1091.13 140.281C1087.7 143.25 1082.76 144.734 1076.33 144.734H1062.93ZM1062.93 138.602H1076.41C1080.42 138.602 1083.49 137.664 1085.62 135.789C1087.76 133.888 1088.83 131.154 1088.83 127.586C1088.83 124.201 1087.76 121.492 1085.62 119.461C1083.49 117.43 1080.56 116.375 1076.84 116.297H1062.93V138.602ZM1102.3 145.477C1102.3 141.336 1103.11 137.612 1104.73 134.305C1106.37 130.997 1108.63 128.445 1111.52 126.648C1114.44 124.852 1117.76 123.953 1121.48 123.953C1127.24 123.953 1131.89 125.945 1135.43 129.93C1139 133.914 1140.78 139.214 1140.78 145.828V146.336C1140.78 150.451 1139.99 154.148 1138.4 157.43C1136.84 160.685 1134.58 163.224 1131.64 165.047C1128.72 166.87 1125.36 167.781 1121.56 167.781C1115.83 167.781 1111.18 165.789 1107.62 161.805C1104.08 157.82 1102.3 152.547 1102.3 145.984V145.477ZM1109.57 146.336C1109.57 151.023 1110.65 154.786 1112.81 157.625C1115 160.464 1117.92 161.883 1121.56 161.883C1125.23 161.883 1128.15 160.451 1130.31 157.586C1132.47 154.695 1133.55 150.659 1133.55 145.477C1133.55 140.841 1132.45 137.091 1130.23 134.227C1128.05 131.336 1125.13 129.891 1121.48 129.891C1117.92 129.891 1115.04 131.31 1112.85 134.148C1110.66 136.987 1109.57 141.049 1109.57 146.336ZM1156.68 124.734L1156.91 130.047C1160.14 125.984 1164.36 123.953 1169.57 123.953C1178.5 123.953 1183.01 128.992 1183.09 139.07V167H1175.86V139.031C1175.83 135.984 1175.13 133.732 1173.75 132.273C1172.4 130.815 1170.27 130.086 1167.38 130.086C1165.04 130.086 1162.98 130.711 1161.21 131.961C1159.44 133.211 1158.06 134.852 1157.07 136.883V167H1149.84V124.734H1156.68ZM1192.27 145.516C1192.27 138.927 1193.79 133.693 1196.84 129.812C1199.88 125.906 1203.92 123.953 1208.95 123.953C1214.1 123.953 1218.12 125.776 1221.02 129.422L1221.37 124.734H1227.97V165.984C1227.97 171.453 1226.34 175.763 1223.09 178.914C1219.86 182.065 1215.51 183.641 1210.04 183.641C1206.99 183.641 1204.01 182.99 1201.09 181.688C1198.18 180.385 1195.95 178.602 1194.41 176.336L1198.16 172C1201.26 175.828 1205.05 177.742 1209.53 177.742C1213.05 177.742 1215.78 176.753 1217.73 174.773C1219.71 172.794 1220.7 170.008 1220.7 166.414V162.781C1217.81 166.115 1213.87 167.781 1208.87 167.781C1203.92 167.781 1199.91 165.789 1196.84 161.805C1193.79 157.82 1192.27 152.391 1192.27 145.516ZM1199.53 146.336C1199.53 151.102 1200.51 154.852 1202.46 157.586C1204.41 160.294 1207.15 161.648 1210.66 161.648C1215.22 161.648 1218.57 159.578 1220.7 155.438V136.141C1218.49 132.104 1215.17 130.086 1210.74 130.086C1207.23 130.086 1204.48 131.453 1202.5 134.188C1200.52 136.922 1199.53 140.971 1199.53 146.336Z" fill="white"/>
        </g>
      </g>
    </svg>
  );
}

const Login = (): JSX.Element => {
  const UID: string = `1cbdbdbda9ab3cee5773541a19177fa2ae63ae10751dcf3c40466d9a1f0e3f9f`;
  const [twoFactor, setTwoFactor] = useState(false);

  const loginOnClick = () => {
    window.location.href = `${global.BE_HOST}/session/login`;
  };

  useEffect(() => {
    const key = window.location.search.split("=")[0].substr(1);
    const value= window.location.search.split("=")[1];
    if (key === "twoFactor" && value === "email") {
      //console.log("twoFactor");
      setTwoFactor(true);
    }
  }, []);

  if (twoFactor) {
    return (
      <>
        <Modal id={Date.now()} content={<LoginTwoFactor />} smallModal/>
      </>
    );
  }
  return (
    <section id="loginSection">
      <BackGroundPingPongSVG />
      <button id="button" onClick={loginOnClick}>LOGIN</button>
    </section>
  );
};

export default Login;