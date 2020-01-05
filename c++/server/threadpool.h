/*
 * @Descripttion: 线程池
 * @Author: lly
 * @Date: 2019-12-26 14:52:04
 * @LastEditors  : lly
 * @LastEditTime : 2020-01-05 20:21:11
 */
#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "locker.h"

template< typename T>
class  ThreadPool
{
public:
    ThreadPool(int thread_number = 8, int max_requersst = 10000);
    ~ThreadPool();
    bool append(T *request);

private:
    static void * worker(void *arg);
    void run();

private:
    int m_thread_number;        //线程池中的线程数
    unsigned int m_max_requests;         //请求队列中运行最大的请求数
    pthread_t *m_threads;       //描述线程池的数组，其大小为m_thread_number
    std::list<T *> m_workqueue; //请求队列
    Locker m_queuelocker;        //保护请求队列的互斥锁
    Sem m_queuestat;            //是否有任务需要处理
    bool m_stop;                 //是否结束线程
};

template<typename T>
ThreadPool<T>::ThreadPool(int thread_number, int max_requests):
m_thread_number(thread_number),
m_max_requests(max_requests),
m_threads(NULL),
m_stop(false)
{
    if (thread_number <= 0 || max_requests <= 0) {
        throw std::exception();
    }

    m_threads = new pthread_t[m_thread_number];
    if (!m_threads) {
        throw std::exception();
    }

    for (int i = 0; i < m_thread_number; i++) {
        printf("create the %dth thread\n", i);
        
        if (pthread_create(m_threads + i, NULL, worker, this) != 0) {
            delete[] m_threads;
            throw std::exception();
        }

        if (pthread_detach(m_threads[i])) {
            delete [] m_threads;
            throw std::exception();
        }
    }
}

template<typename T>
ThreadPool<T>::~ThreadPool
()
{
    delete[] m_threads;
    m_stop = true;
}

template<typename T>
void *ThreadPool<T>::worker(void *arg)
{
    ThreadPool *pool = (ThreadPool *)arg;
    pool->run();
    return pool;
}

template<typename T>
void ThreadPool<T>::run()
{
    while (!m_stop) {
        m_queuestat.wait();
        m_queuelocker.lock();
        if (m_workqueue.empty()) {
            m_queuelocker.unlock();
            continue;
        }
        T *request = m_workqueue.front();
        m_workqueue.pop_front();
        m_queuelocker.unlock();

        if (!request) {
            continue;
        }
        request->process();
    }
}

template<typename T>
bool ThreadPool<T>::append(T *request) {
    m_queuelocker.lock();
    if (m_workqueue.size() > m_max_requests) {
        m_queuelocker.unlock();
        return false;
    }
    m_workqueue.push_back(request);
    m_queuelocker.unlock(); 
    m_queuestat.post();
    return true;
}

#endif