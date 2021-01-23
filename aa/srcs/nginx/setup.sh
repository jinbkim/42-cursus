#!/bin/sh

mkdir -p /etc/nginx/ssl
chmod 600 /etc/nginx/ssl/tls.key /etc/nginx/ssl/tls.crt
openssl req -x509 -nodes -newkey rsa:2048 -keyout /etc/nginx/ssl/tls.key -out /etc/nginx/ssl/tls.crt -days 365 -subj '/CN=localhost'

ssh-keygen -A
adduser --disabled-password ${SSH_USERNAME}
echo "${SSH_USERNAME}:${SSH_PASSWORD}" | chpasswd

mkdir -p /run/nginx
mkdir -p /usr/share/nginx/html
echo "FT_SERVICES" >> /usr/share/nginx/html/index.html

/usr/sbin/sshd
/usr/sbin/nginx -g "daemon off;"