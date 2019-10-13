FROM leiyudaye/ubuntu16.04:base

# 更新源
COPY sources.list /root

RUN cp /etc/apt/sources.list /etc/apt/sources.list_16.04 \
	&& mv /root/sources.list /etc/apt/sources.list

# 下载基础工具集
RUN apt-get update && apt-get install -y net-tools wget curl zip python3.5 \
	&& rm -rf /var/lib/apt/lists

ENV WORKDIR=/root
