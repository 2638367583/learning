FROM leiyudaye/centos7:base

# 安装mysql 编译环境
RUN yum makecache
RUN yum -y install gcc gcc-c++ make autoconf cmake \
libtool-ltdl-devel gd-devel freetype-devel libxml2-devel \
libjpeg-devel libpng-devel openssl-devel curl-devel bison patch unzip \
libmcrypt-devel libmhash-devel ncurses-devel sudo bzip2 flex libaio-devel
RUN yum -y install wget curl

# 编译mysql
RUN cd /root && wget http://dev.mysql.com/get/Downloads/MySQL-5.6/mysql-5.6.15.tar.gz \
    && tar zxf mysql-5.6.15.tar.gz \
    && cd mysql-5.6.15 \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local/webserver/mysql/ -DMYSQL_UNIX_ADDR=/tmp/mysql.sock \
    -DDEFAULT_CHARSET=utf8 -DDEFAULT_COLLATION=utf8_general_ci -DWITH_EXTRA_CHARSETS=all \
    -DWITH_MYISAM_STORAGE_ENGINE=1 -DWITH_INNOBASE_STORAGE_ENGINE=1 -DWITH_MEMORY_STORAGE_ENGINE=1 \
    -DWITH_READLINE=1 -DWITH_INNODB_MEMCACHED=1 -DWITH_DEBUG=OFF -DWITH_ZLIB=bundled -DENABLED_LOCAL_INFILE=1 \
    -DENABLED_PROFILING=ON -DMYSQL_MAINTAINER_MODE=OFF -DMYSQL_DATADIR=/usr/local/webserver/mysql/data \
    -DMYSQL_TCP_PORT=3306

# 编译lua
RUN yum -y install readline-devel
RUN cd /root && wget http://www.lua.org/ftp/lua-5.3.0.tar.gz \
	&& tar zxf lua-5.3.0.tar.gz \
	&& cd lua-5.3.0 \
	&& make linux test \
	&& make install