
/**
 * 由于一个数值重复的次数超过了一半，所以中间的数值就是这个数，所以可以先排序好，之后取中间的数值
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quickSort( vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int proit = arr.at(right);
    while (i < j) {
        while (arr[i] <= proit && i < j) {
            i++;
        }

        while (arr[j] >= proit && i < j) {
            j--;
        }
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    arr[right] = arr[i];
    arr[i] = proit;
    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> arr{6,7,9,8,5, 0,1,3,1,5};
    //sort(arr.begin(), arr.end(), [](int x, int y) {if (x < y) return true;});
    quickSort(arr, 0, arr.size()-1);
//    for (auto num : arr) {
//        cout << num << endl;
//    }
    if (!arr.empty()) {
        cout << arr.at(arr.size() / 2) << endl;
    }

    return 0;
}