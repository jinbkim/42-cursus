FROM alpine:3.12.0
#FROM alpine:latest

RUN apk update \
		&& apk --update --no-cache add \
                nginx \
                openssl \
                openssh-server

COPY ./setup.sh /usr/sbin/setup.sh
RUN chmod +x /usr/sbin/setup.sh
COPY ./default.conf /etc/nginx/conf.d/
COPY ./proxy.conf /etc/nginx/conf.d/

EXPOSE 80 443 22

ENTRYPOINT ["/usr/sbin/setup.sh"]
