#include <iostream>

int clear_space(char *str)
{
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len+1; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    //减去非空格的字符个数，剩下的就是空格的个数
    return len - j + 1;
}

int main()
{
    char str[1024] = " te st   te st ";
    int count = clear_space(str);

    printf("str=x%sx, count=%d\n", str, count);
    return 0;
}