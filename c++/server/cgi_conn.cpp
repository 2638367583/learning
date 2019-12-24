/*
 * @Descripttion: cgi执行类
 * @Author: lly
 * @Date: 2019-12-20 01:12:22
 * @LastEditors  : lly
 * @LastEditTime : 2019-12-24 23:31:58
 */
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#include "cgi_conn.h"

/**
 * @brief: 从epoll事件队列中提出fd
 * @param int epollfd epoll事件描述符
 * @param int fd 文件描述符
 * @return: void
 */
static void removefd(int epollfd, int fd)
{
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

/**
 * @brief: 构造函数
 * @param void
 * @return: void
 */
CgiConn::CgiConn():
m_sockfd(-1),
m_read_idx(0)
{
    bzero(&m_addr, sizeof(m_addr));
}

/**
 * @brief: 析构函数
 * @param void
 * @return: void
 */
CgiConn::~ CgiConn()
{
}

/**
 * @brief: cgi初始化
 * @param int epollfd epoll事件描述符
 * @param int sockfd 客户端套接字
 * @param sockaddr_in addr 客户端地址信息
 * @return: void
 */
void CgiConn::init(int epollfd, int sockfd, struct sockaddr_in addr) 
{
    m_epollfd =  epollfd;
    m_sockfd = sockfd;
    m_addr = addr;
    //打印ip和port
    printf("client addr:%s, port:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
}

/**
 * @brief: cgi处理函数
 * @param void
 * @return: void
 */
void CgiConn::process()
{
    int ret = -1;
    int idx = 0;
    while(true) {
        idx = m_read_idx;
        ret = recv(m_sockfd, m_buf + m_read_idx, BUFF_SIZE - 1 - m_read_idx, 0);
        if (ret < 0) {
            if (errno != EAGAIN) {
                removefd(m_epollfd, m_sockfd);
            }
            break;
        //对方主动断开连接
        } else if (ret == 0) {
            removefd(m_epollfd, m_sockfd);
            break;
        } else {
            m_read_idx += ret;
            printf("user content is: %s\n", m_buf);
            for (; idx < m_read_idx; ++idx) {
                if ((idx >= 1) && (m_buf[idx-1] == ' ') && (m_buf[idx] == 'H')) {
                    break;
                }
            }
            if (idx == m_read_idx) {
                continue;
            }
            m_buf[idx - 1] = '\0';

            char file_name[128] = {0};
            strcpy(file_name, m_buf+3);
            /*GET / HTTP/1.0*/
            //char *file_name = m_buf;
            printf("file_name:%s\n", file_name);
            if (access(file_name, F_OK) == -1) {
                removefd(m_epollfd, m_sockfd);
                break;
            }
            ret = fork();
            if (ret == -1) {
                removefd(m_epollfd, m_sockfd);
                break;
            } else if (ret > 0) {
                removefd(m_epollfd, m_sockfd);
                break;
            } else {
                close(STDOUT_FILENO);
                dup(m_sockfd);
                execl(m_buf, m_buf, 0);
                exit(0);
            }
        }
    }
}