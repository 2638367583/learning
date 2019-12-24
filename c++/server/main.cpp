#include <strings.h>

#include "processpool.h"
#include "cgi_conn.h"

char ip[] = "0.0.0.0";
short port = 12345;

int main(int argc, char *argv[]) 
{
    //初始化套接字
    sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    //绑定ip
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &addr.sin_addr);
    addr.sin_port = htons(port);
    int ret = bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));
    assert (ret != -1);

    //监听套接字
    ret = listen(listenfd, 5);
    assert(ret != -1);

    //开启进程池处理
    Processpool<CgiConn> *pool = Processpool<CgiConn>::create(listenfd, 8);
    pool->run();

    return 0;
}