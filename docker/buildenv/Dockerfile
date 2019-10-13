FROM leiyudaye/ubuntu16.04:base

# 下载编译工具集
RUN apt-get update 
RUN apt-get install -y gcc

# 安装lua环境
RUN apt-get install -y libreadline-dev  readline-devel
RUN cd $WORKDIR && curl -R -O http://www.lua.org/ftp/lua-5.3.0.tar.gz \
	&& tar zxf lua-5.3.0.tar.gz \
	&& cd lua-5.3.0 \
	&& make linux test \
	&& make install

ENV WORKDIR=/root
