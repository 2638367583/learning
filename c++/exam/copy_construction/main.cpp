#include <iostream>
#include <cstring>
#include <cstdlib>

class String {
public:
    String () {
        p = new char[1024]{'a', 'b', 'c'};
    }

    String(const String &s) {
        operator=(s);
    }

    String &operator = (const String &cp) {
        //浅拷贝
        //this->p = cp.p;

        //深拷贝
        if (this->p != NULL) {
            delete [] this->p;
        }

        this->p = new (std::nothrow) char[1024];
        memset(p, 0, 1024);
        strncpy(this->p, cp.p, 1024);

        return *this;
    }

    void printAddr() {
        printf("p addr: %p\n", this->p);
        printf("p value: %s\n", this->p);
    }
private:
    char *p = NULL;
};


int main() {
    String strA;
    strA.printAddr();
    //拷贝构造
    String strB(strA);

    //复制重载
//    strB = strA;
    strB.printAddr();
    return 0;
}