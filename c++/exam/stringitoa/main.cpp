#include <iostream>
#include <cstdio>
#include <cstdlib>

int main1() {
    double num1 = 435.10000001;
    int num2 = 435;

    char buf[30];

//    gcvt(num1, 8, buf);

//    std::cout << buf << std::endl;

    snprintf(buf, sizeof(buf), "%lf", num1);

    std::cout << buf << std::endl;

    snprintf(buf, sizeof(buf), "%d", num2);

    std::cout << buf << std::endl;

    return 0;
}

void int2str(int n, char *str)
{
    if (str == NULL) {
        return;
    }

    char buf[10] = "";
    int i = 0;
    int len = 0;
    int temp = abs(n);
    while(temp) {
        buf[i++] = (temp % 10) + '0';
        temp = temp / 10;
    }

    std::cout << buf << std::endl;

    len = n < 0 ? ++i : i;

    str[i] = 0;

    while(1) {
        i--;
        if (buf[len -i -1] == 0) {
            break;
        }
        str[i] = buf[len-i-1];
    }
    if (i == 0) {
        str[i] = '-';
    }

    std::cout << str << std::endl;

}

int main()
{
    char str[30];
    int2str(-1024, str);

    return 0;
}
