/*
 * @Descripttion: 描述进程的类
 * @Author: lly
 * @Date: 2019-12-15 16:30:10
 * @LastEditors  : lly
 * @LastEditTime : 2019-12-24 23:04:07
 */
#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <unistd.h>

class Process
{
public:
    explicit Process();
    ~Process();

public:
    pid_t m_pid;
    int m_pipe[2];
};

#endif