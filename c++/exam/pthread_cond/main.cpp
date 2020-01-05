#include <iostream>
#include <pthread.h>
#include <unistd.h>

class FooBar {
private:
    int n;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    int count;
    bool flag;

public:
    FooBar(int n) {
        this->n = n;
        pthread_cond_init(&cond, NULL);
        pthread_mutex_init(&mutex, NULL);
        count = 0;
        flag = true;
    }

    ~FooBar() {
        pthread_cond_destroy(&cond);
        pthread_mutex_destroy(&mutex);
    }

    void foo1() {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex);
            while(flag == false) {
//                std::cout << "foo+++++wait\n";
                pthread_cond_wait(&cond, &mutex);
            }
            std::cout << "foo" << ++count << std::endl;
            flag = false;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    void bar1() {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex);
            while (flag == true) {
//                std::cout << "bar+++++wait\n";
                pthread_cond_wait(&cond, &mutex);
            }
            std::cout << "bar" << --count << std::endl;
            flag = true;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    static void *foo(void *arg) {
        FooBar *foo = (FooBar *)arg;
        foo->foo1();
    }

    static void *bar(void *arg) {
        FooBar *foo = (FooBar *)arg;
        foo->bar1();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    FooBar *foo = new FooBar(100);
    pthread_t pid1;
    pthread_t pid2;
    pthread_create(&pid1, NULL, foo->foo, foo);
    pthread_create(&pid2, NULL, foo->bar, foo);

    pthread_detach(pid1);
    pthread_detach(pid2);
    while(true);
    delete foo;
    return 0;
}