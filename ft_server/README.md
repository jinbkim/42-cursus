# ft_server 대충공부 순서
## (통과만을위한 최소한의 공부만했음. 클러스터 맥 vnc 환경.)

1. docker , 42tool box설치
2. 데비안 버스터로 이미지 빌드
3. apt-get 을 이용해서 update, vim, wget 설치
4. nginx 설치
5. /etc/nginx/sites-available 에서 default 파일 수정.
6. php 시리즈, mariadb, mysql 설치
8. /var/www/html 에서 phpMyAdmin 설치
9. /var/www/html/phpMyAdmin 에서 config.sample.inc.php 을 이용해서 config.inc.php 파일 만들고 수정.
10. /var/www/html 에서 wordpress 설치
11. /var/www/html/wordpress 에서 wp-sample-config.php 을 이용해서 wp-config.php 파일 만들고 수정.
12. SSL key 발급받고, /etc/nginx/sites-available 에서 default 파일 수정.
13. autoindex 기능 구현을 위해 /etc/nginx/sites-available 에서 default 파일 수정.
14. 위의 과정들을 한번에 할 Dockerfile 만들기

## 평가하기
1. SSL 확인. (localhost에 들어갔을때 https로 잘 들어가지는지)
2. localhost/phpMyAdmin 확인. (로그인 하고 들어가서 wordpress db 있는지)
3. localhost/wordpress 확인(로그인 하고 들어가서 페이지 잘만들어지는지.)
4. autoindex 기능 확인