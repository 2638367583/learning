#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ev.h>

void timeout(struct ev_loop *main_loop, ev_timer *timer, int e)
{
    printf("timeout.\n");

    // ev_timer_stop(main_loop, timer);
}

int main(int argc, char *argv[])
{
    struct ev_loop *main_loop = ev_default_loop(0);

    ev_timer timer;
   
    // ev_init(&timer, timeout);
    // ev_timer_set(&timer, 2, 10);

    //定时器初始化函数，timeout为处理函数，2为2后开始计时，10为1s调一次timeout
    ev_timer_init(&timer, timeout, 2, 10);

    ev_timer_start(main_loop, &timer);

    ev_run(main_loop, 0);

    return 0;
}

