#include <iostream>
#include <vector>
#include <limits>
/**
 *
 * 对于vector<int> v = {1, 2, 3, 5, 7, -2 -1, 0}，其中有些相邻的元素值是连续的，有些不连续。
    写一个函数，输出这个数组中的元素，对于连续相邻的元素，只输出两端；对于不连续的元素，输出该数值本身。
    例如上面的v，输出如下：
    1->3
    5
    7
    -2->0
 */

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> v = {1, 2, 3, 5, 7, 1, 2, 3, 4, 5, 6, 5,-2, -1, 0, 5};
    int preIndex = 0;
    for (int i=0; i<v.size()-1; i++) {
        if (v.at(i) + 1 == v.at(i + 1)) {
            continue;
        } else if (preIndex < i - 1 ) {
            cout << v.at(preIndex) << "->" << v.at(i) << endl;
            preIndex = i + 1;
        } else {
            cout << v.at(i) << endl;
            preIndex = i + 1;
        }
    }
    if (preIndex < v.size() - 2) {
        cout << v.at(preIndex) << "->" << v.at(v.size()-1) << endl;
    } else {
        cout << v.at(v.size()-1);
    }
    return 0;
}