FROM alpine:3.10

RUN apk update \
		&& apk --update --no-cache add \
				mysql \
				mysql-client

RUN addgroup mysql mysql

COPY ./setup.sh /usr/sbin/setup.sh
RUN chmod +x /usr/sbin/setup.sh
COPY my.cnf /etc/mysql/my.cnf
RUN chmod 644 /etc/mysql/my.cnf

EXPOSE 3306

ENTRYPOINT ["/usr/sbin/setup.sh"]