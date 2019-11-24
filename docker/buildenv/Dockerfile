FROM leiyudaye/ubuntu16.04:v1

# 下载编译工具集
RUN apt-get update 

# 安装mysql编译环境
RUN apt-get install -y gcc g++ make autoconf cmake bison libncurses5-dev build-essential

# 安装lua环境
RUN apt-get install -y libreadline-dev
RUN cd $WORKDIR && curl -R -O http://www.lua.org/ftp/lua-5.3.0.tar.gz \
	&& tar zxf lua-5.3.0.tar.gz \
	&& cd lua-5.3.0 \
	&& make linux test \
	&& make install

ADD mysql-5.6.46.tar.gz $WORKDIR

RUN cd $WORKDIR/mysql-5.6.46 \
	&& cmake . -DCMAKE_INSTALL_PREFIX=/usr/local/mysql -DMYSQL_DATADIR=/usr/local/mysql/data \
-DSYSCONFDIR=/etc -DWITH_INNOBASE_STORAGE_ENGINE=1 -DWITH_ARCHIVE_STORAGE_ENGINE=1 \
-DWITH_BLACKHOLE_STORAGE_ENGINE=1 -DWITH_PARTITION_STORAGE_ENGINE=1 -DWITH_PERFSCHEMA_STORAGE_ENGINE=1 \
-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1 -DWITHOUT_FEDERATED_STORAGE_ENGINE=1 -DDEFAULT_CHARSET=utf8 \
-DDEFAULT_COLLATION=utf8_general_ci -DWITH_EXTRA_CHARSETS=all -DENABLED_LOCAL_INFILE=1 -DWITH_READLINE=1 \
-DMYSQL_UNIX_ADDR=/usr/local/mysql/mysql.sock -DMYSQL_TCP_PORT=3306 -DMYSQL_USER=mysql \
-DCOMPILATION_COMMENT="lq-edition" -DENABLE_DTRACE=0 -DOPTIMIZER_TRACE=1 -DWITH_DEBUG=1 \
	&& maek \
	&& make install

RUN apt-get install -y inetutils-ping vim strace
# kernel moudle工具
RUN apt-get install -y kmod