#ifndef __CgiConn_H__
#define __CgiConn_H__
#include <netinet/in.h>
#include <stdio.h>
#include "processpool.h"

class CgiConn
{
private:
    /* data */
public:
    CgiConn(/* args */);
    ~CgiConn();
    void init(int epollfd, int sockfd, struct sockaddr_in addr);
    void process();

private:
    static const int BUFF_SIZE = 1024;
    struct sockaddr_in m_addr;
    int m_epollfd;
    int m_sockfd;
    char m_buf[BUFF_SIZE];
    int m_read_idx;
};


#endif