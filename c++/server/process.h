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