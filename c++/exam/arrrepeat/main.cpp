/**
 * 找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 
限制：

2 <= n <= 100000
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //方法一，下标定位法
        vector<int> location(nums.size(), 0);
        for (auto &num : nums) {
            if (location[num] == 0) {
                location[num] += 1;
            } else {
                return num;
            }
        }
        return -1;
    }

    int findRepeatNumber2(vector<int> &nums) {
        //方法二， Set集合法
        set<int> set;
        for (auto &num : nums) {
            auto iter = set.find(num);
            if (iter != set.end()) {
                return num;
            } else {
                set.insert(num);
            }
        }
        return -1;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Solution solt;
    vector<int> vec = {2, 3, 1, 0, 2, 5, 3};
    cout << solt.findRepeatNumber(vec) << endl;
    cout << solt.findRepeatNumber2(vec) << endl;
    return 0;
}