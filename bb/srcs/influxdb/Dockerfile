FROM alpine:3.10

RUN apk update \
		&& apk --update --no-cache add \
                influxdb

RUN mkdir -p /etc/influxdb
RUN mkdir -p /var/lib/influxdb
COPY influxdb.conf /etc/influxdb/influxdb.conf
EXPOSE 8086

COPY ./setup.sh  /usr/sbin/setup.sh
RUN chmod +x /usr/sbin/setup.sh

ENTRYPOINT ["/usr/sbin/setup.sh"]
