#include <strings.h>
// #include <errno.h>
// #include <unistd.h>

#include "cgi_conn.h"
// #include "processpool.h"

static void removefd(int epollfd, int fd)
{
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

CgiConn::CgiConn(/* args */):
m_sockfd(-1),
m_read_idx(0)
{
    bzero(&m_addr, sizeof(m_addr));
}

 CgiConn::~ CgiConn()
{
}

void CgiConn::init(int epollfd, int sockfd, struct sockaddr_in addr) 
{
    m_epollfd =  epollfd;
    m_sockfd = sockfd;
    m_addr = addr;
    printf("accept :%d\n", ntohs(addr.sin_port));
}

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
                if ((idx >= 1) && (m_buf[idx-1] == '\r') && (m_buf[idx] == '\n')) {
                    break;
                }
            }
            if (idx == m_read_idx) {
                continue;
            }
            m_buf[idx - 1] = '\0';
            char *file_name = m_buf;
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