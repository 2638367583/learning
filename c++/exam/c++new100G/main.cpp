#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int *p = new int[1024*1024*1024*100];
    printf("%p\n",p);
    p[1024*1024*1024*10]  = 1;
    return 0;
}