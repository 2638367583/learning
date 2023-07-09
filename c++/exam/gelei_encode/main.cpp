/**
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
示例 1:
输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2
对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。
00 - 0
10 - 2
11 - 3
01 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

void gl_encode(vector<int> &vec, int n) {
    vec.clear();
    vec.push_back(0);
    int bt = 0;
    while (n--) {
        int size = vec.size();
        for (int i=size-1; i>=0; i--) {
            vec.push_back(vec.at(i) + (1<<bt));
        }
        bt++;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec;
    gl_encode(vec, 2);
    for (auto num : vec) {
        cout << num;
    }
    cout << endl;
    gl_encode(vec, 3);
    for (auto num : vec) {
        cout << num;
    }
    return 0;
}