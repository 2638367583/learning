#include <iostream>

int stepInWater(int *arr, int size)
{
    int maxValue = 0;
    int maxValueIndex = 0;
    int total = 0;
    int maxLeft = 0;
    int maxRight = 0;
    for (int i=0; i<size; i++) {
        if (maxValue < arr[i]) {
            maxValue = arr[i];
            maxValueIndex = i;
        }
    }
    std::cout << "max value[" << maxValueIndex << "]" << "=" << maxValue << std::endl;

    //从左边遍历，获取左边的注水块
    for (int i=0; i<maxValueIndex; i++) {
        if (maxLeft < arr[i]) {
            maxLeft = arr[i];
        } else {
            total += maxLeft - arr[i];
        }
    }
    //从右边遍历，获取右边的注水块
    for (int i = size - 1; i > maxValueIndex; i--) {
        if (maxRight < arr[i]) {
            maxRight = arr[i];
        } else {
            total += maxRight - arr[i];
        }
    }
    return total;
}

int stepInWater2(int *arr, int size)
{
    int count = 0;
    while (true) {
        //寻找到左边不为0的数
        int i = 0;
        while (arr[i] <= 0) {
            if (i >= size) {
                break;
            }
            i++;
        }

        //寻找到右边不为0的数
        int j = size - 1;
        while (arr[j] <= 0) {
            if (j <= 0) {
                break;
            }
            j--;
        }

        //没找到或只有一个数时退出循环
        if (i == j) {
            break;
        }

        //计算出每个水平方向的注水块
        for (int k = i; k <= j; k++) {
            if (arr[k] <= 0) {
                count++;
            } else {
                arr[k] -= 1;
            }
        }
    }
    return count;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int arr[12] = {0,1,0,2,0,3,1,0,1,2,0,1};
    std::cout << stepInWater2(arr, 12);
    return 0;
}