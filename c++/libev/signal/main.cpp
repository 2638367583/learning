#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ev.h>

void sig_int_handle(struct ev_loop *main_loop, ev_signal *sig, int e)
{
    printf("recevicer SIGINT signal.\n");
    // ev_signal_stop(main_loop, sig);
    // ev_break(main_loop);
}

void sig_quit_handle(struct ev_loop *main_loop, ev_signal *sig, int e)
{
    printf("recevicer SIGQUIT signal.\n");
    // ev_signal_stop(main_loop, sig);
    // ev_break(main_loop);
}

int main(int argc, char *argv[])
{
    struct ev_loop *main_loop = ev_default_loop(0);

    //SIGINI信号处理
    ev_signal sig_int;

    ev_init(&sig_int, sig_int_handle);

    ev_signal_set(&sig_int, SIGINT);

    ev_signal_start(main_loop, &sig_int);

    //SIGQUIT信号
    ev_signal sig_quit;

    ev_init(&sig_quit, sig_quit_handle);

    ev_signal_set(&sig_quit, SIGQUIT);

    ev_signal_start(main_loop, &sig_quit);

    ev_run(main_loop, 0);

    return 0;
}

