#include <iostream>
#include <pthread.h>

//懒汉式单例
class LazySingleton
{
private:
    LazySingleton() {}


public:
    ~LazySingleton(){}
    static LazySingleton * getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        return instance;
    }

    void print() {
        std::cout << "懒汉式单例" << std::endl;
    }

private:
    static LazySingleton *instance;
};

LazySingleton * LazySingleton::instance = nullptr;

//饿汉式
class HungrySingleton {
private:
    HungrySingleton(){}
    ~HungrySingleton(){}

public:
    static HungrySingleton * getInstance() {
        return instance;
    }

    void print() {
        std::cout << "饿汉式单例" << std::endl;
    }

private:
    static HungrySingleton *instance;
};

HungrySingleton *HungrySingleton::instance = new HungrySingleton();

class DobuleLockSingleton {
private:
    DobuleLockSingleton(){}
    ~DobuleLockSingleton(){}

public:
    static DobuleLockSingleton *getInstance() {
        if (0 != pthread_mutex_init(&mutex, NULL)) {
            return instance;
        }
        if (instance == NULL) {
            pthread_mutex_lock(&mutex);
            if (instance == NULL) {
                instance = new DobuleLockSingleton();
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    void print() {
        std::cout << "双校验锁单例" << std::endl;
    }

private:
    static DobuleLockSingleton *instance;
    static pthread_mutex_t mutex;
};
DobuleLockSingleton *DobuleLockSingleton::instance = NULL;
pthread_mutex_t DobuleLockSingleton::mutex;

int main() {
    std::cout << "Hello, World!" << std::endl;
    //懒汉式
    LazySingleton::getInstance()->print();

    //饿汉式
    HungrySingleton::getInstance()->print();

    //双校验锁
    DobuleLockSingleton::getInstance()->print();

    return 0;
}