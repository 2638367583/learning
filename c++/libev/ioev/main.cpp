#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ev.h>

void io_action(struct ev_loop *main_loop,ev_io *io_w,int e)
{
    FILE *fp = NULL;
    char buffer[256] = {0};
    
    fp = fopen("./stdin.txt", "a");

    if (fp == NULL) {
        printf("Failed to open file.\n");
        return ;
    }
    read(STDIN_FILENO, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    fwrite(buffer, strlen(buffer), 1, fp);

    fclose(fp);

    //停止事件循环
    // ev_io_stop(main_loop,io_w);
}

int main(int argc, char *argv[])
{
    //事件主循环
    struct ev_loop *main_loop = ev_default_loop(0);

    //io 事件
    ev_io io;
    
    //绑定io事件对对应的处理函数
    ev_init(&io, io_action);

    //设置事件对应的fd与事件类型
    ev_io_set(&io, STDIN_FILENO, EV_READ);

    //绑定到主事件循环中
    ev_io_start(main_loop, &io);

    //启动事件循环
    ev_run(main_loop, 0);

    return 0;
}

