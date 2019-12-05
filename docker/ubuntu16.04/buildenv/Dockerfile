FROM leiyudaye/ubuntu16.04:base

# 更新源
COPY sources.list /root

RUN cp /etc/apt/sources.list /etc/apt/sources.list_16.04 \
	&& mv /root/sources.list /etc/apt/sources.list

# 下载基础工具集
RUN apt-get update && apt-get install -y net-tools wget curl zip python3.5 inetutils-ping vim strace

# kernel moudle工具
RUN apt-get install -y kmod

# 配置工作目录
ENV WORKDIR=/root
WORKDIR $WORKDIR

# 安装mysql编译环境
RUN apt-get install -y gcc g++ make autoconf cmake bison libncurses5-dev build-essential

# 安装lua环境
RUN apt-get install -y libreadline-dev
RUN cd $WORKDIR && curl -R -O http://www.lua.org/ftp/lua-5.3.0.tar.gz \
	&& tar zxf lua-5.3.0.tar.gz \
	&& cd lua-5.3.0 \
	&& make linux test \
	&& make install \
	&& cd ${WORKDIR} \
	&& rm -rf lua-5.3.0*

# ADD mysql-5.6.46.tar.gz $WORKDIR

# RUN cd $WORKDIR/mysql-5.6.46 \
# 	&& cmake . -DCMAKE_INSTALL_PREFIX=/usr/local/mysql -DMYSQL_DATADIR=/usr/local/mysql/data \
# -DSYSCONFDIR=/etc -DWITH_INNOBASE_STORAGE_ENGINE=1 -DWITH_ARCHIVE_STORAGE_ENGINE=1 \
# -DWITH_BLACKHOLE_STORAGE_ENGINE=1 -DWITH_PARTITION_STORAGE_ENGINE=1 -DWITH_PERFSCHEMA_STORAGE_ENGINE=1 \
# -DWITHOUT_EXAMPLE_STORAGE_ENGINE=1 -DWITHOUT_FEDERATED_STORAGE_ENGINE=1 -DDEFAULT_CHARSET=utf8 \
# -DDEFAULT_COLLATION=utf8_general_ci -DWITH_EXTRA_CHARSETS=all -DENABLED_LOCAL_INFILE=1 -DWITH_READLINE=1 \
# -DMYSQL_UNIX_ADDR=/usr/local/mysql/mysql.sock -DMYSQL_TCP_PORT=3306 -DMYSQL_USER=mysql \
# -DCOMPILATION_COMMENT="lq-edition" -DENABLE_DTRACE=0 -DOPTIMIZER_TRACE=1 -DWITH_DEBUG=1 \
# 	&& maek \
# 	&& make install