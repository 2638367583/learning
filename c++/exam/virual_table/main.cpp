#include <iostream>

class VirualTable {
public:
    virtual void a() {std::cout << "a" << std::endl;}

    int b=0;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    VirualTable vTable;

    std::cout << sizeof(vTable);
    return 0;
}