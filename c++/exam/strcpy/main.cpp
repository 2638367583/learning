#include <iostream>

char *strcpy(char *dst, const char *src)
{
    if (dst == NULL || src == NULL) {
        return NULL;
    }

    char *q = dst;
    while ((*q++ = *src++) != '\0');

    return dst;
}

char *strncpy(char *dst, const char *src, int n)
{
    if (dst == NULL || src == NULL || n <= 0) {
        return NULL;
    }
    int count = 0;
    char *q = dst;
    while ((*q++ = *src++) != '\0') {
        if (++count == n) {
            break;
        }
    }

    return dst;
}

void *memcpy(void *dst, const void *src, int n)
{
    if (dst == NULL || src == NULL || n <= 0) {
        return NULL;
    }

    char *p = (char*)src;
    char *q = (char*)dst;
    if (src < dst && src <= q + n) {
        while (--n >= 0) {
            *(q+n) = *(p+n);
            printf("%d", 1);
        }
    } else {
        while (n-- > 0) {
            *q++ = *p++;
        }
    }

    return dst;
}

int main() {
        char src[] = "abcdefghijq";
        char dst[] = "abcdjhjhjhjhjhj";

//        strcpy(dst, src);
//        strncpy(dst, src, 20);
        memcpy(src+2, src, 5);
        std::cout << src << std::endl;
        return 0;
}