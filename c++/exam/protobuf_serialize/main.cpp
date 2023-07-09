#include <iostream>

int main() {

    std::cout << "Hello, World!" << std::endl;
    int src = 0b1000000000000010;
    char buf[4];
    buf[0] = 0b10000001;
    buf[1] = 0b00000010;
    buf[2] = 0b00000010;
    buf[3] = 0b10000010;
    buf[4] = 0b00000010;


    int dst64 = 0;
    int n = 0;
    int base = 0;
    while (n < 5) {
        dst64 = dst64 | ((buf[n] & 0b01111111) << (7 * base++));
        if ((buf[n] >> 7) == 0) {
            std::cout << dst64;
            dst64 = 0;
            base = 0;
        }
        n++;
    }


    return 0;
}