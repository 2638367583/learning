#include <iostream>

union byteorder {
    short num;
    char order[sizeof(short)];
} byteorder;

int main() {
    byteorder.num = 0x0102;
    printf("union byteorder size: %ld\n", sizeof(byteorder));
    printf("byteorder num = %d\n", byteorder.num);
    printf("byteorder order[0] %p = %x, byteorder order[1] %p =%x\n",
           &byteorder.order[0],byteorder.order[0],
           &byteorder.order[1], byteorder.order[1]);

    if ((byteorder.order[0] == 1) && (byteorder.order[1] == 2)) {
        printf("big endian.\n");
    } else if((byteorder.order[0] == 2) && (byteorder.order[1] == 1)){
        printf("litter endian.\n");
    }

    return 0;
}