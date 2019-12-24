/*
 * @Descripttion: cgi执行类
 * @Author: lly
 * @Date: 2019-12-20 00:54:10
 * @LastEditors  : lly
 * @LastEditTime : 2019-12-24 23:12:08
 */
#ifndef __CgiConn_H__
#define __CgiConn_H__

#include <netinet/in.h>
class CgiConn
{
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