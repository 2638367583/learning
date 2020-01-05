#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <pthread.h>

//#include <functional>

class Foo {

private:
    sem_t sem1;
    sem_t sem2;
    sem_t sem3;

public:
    Foo() {
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
        sem_init(&sem3 ,0, 1);
    }

    ~Foo() {
        sem_destroy(&sem1);
        sem_destroy(&sem2);
        sem_destroy(&sem3);
    }

    void first() {
        // printFirst() outputs "first". Do not change or remove this line.
        sem_wait(&sem3);
        std::cout <<  "first" << std::endl;
        sem_post(&sem1);
    }

    void second() {
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&sem1);
        std::cout << "second" << std::endl;
        sem_post(&sem2);
    }

    void third() {
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&sem2);
        std::cout << "third" << std::endl;
        sem_post(&sem3);
    }
};

void *one(void *arg) {
//    std::cout << "thread one:" << pthread_self() << std::endl;
    Foo *fo = (Foo*) arg;
    if (fo != NULL) {
        while (true) {
            fo->first();
        }
    }
}

void *two(void *arg) {
//    std::cout << "thread two:" << pthread_self() << std::endl;
    Foo *fo = (Foo*) arg;
    if (fo != NULL) {
        while(true) {
            fo->second();
        }
    }
}

void *third(void *arg) {
//    std::cout << "thread third:" << pthread_self() << std::endl;
    Foo *fo = (Foo*) arg;
    if (fo != NULL) {
        while (true) {
            fo->third();
        }
    }
}

int main() {
    pthread_t pid1 = 0;
    pthread_t pid2 = 0;
    pthread_t pid3 = 0;

    Foo *fo = new Foo;
//    std::cout << "thread main:" << pthread_self() << std::endl;

    pthread_create(&pid1, NULL, one, fo);
    pthread_create(&pid2, NULL, two, fo);
    pthread_create(&pid3, NULL, third, fo);

    pthread_detach(pid1);
    pthread_detach(pid2);
    pthread_detach(pid3);

    while(1);
    return 0;
}
