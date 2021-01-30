FROM alpine:3.12.0
#FROM alpine:latest

# RUN apk update \
# 		&& apk --update --no-cache add \
#                 telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/

# RUN	echo "@testing http://nl.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories \
# 	&& apk update \
# 	&& apk add --no-cache telegraf@testing

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz
RUN tar -C . -xzf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN cp -r telegraf-1.15.3/* /
RUN ln -s /bin/sh bash

COPY ./setup.sh /usr/sbin/setup.sh
RUN chmod +x /usr/sbin/setup.sh

ENTRYPOINT ["/usr/sbin/setup.sh"]
