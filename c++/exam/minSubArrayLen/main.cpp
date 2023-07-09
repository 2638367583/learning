#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    enum {
        UNKNOW,
        UP,
        DOWN
    };
    int minSubArrayLen(int s, vector<int>& nums) {
        int orientation = UNKNOW;
        int min_subarray_len = nums.size() + 1;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= s) {
                return 1;
            }
            if (i <= start) {
                continue;
            }

            //递增
            if (nums[i - 1] + 1 == nums[i]) {
                if (orientation == DOWN) {
                    start = i - 1;
                }
                orientation = UP;
                int total = 0;
                for (int j = i; j >= start; j--) {
                    total += nums[j];
                    if (total >= s) {
                        min_subarray_len = min(min_subarray_len, i - j + 1);
                    }
                }

                //递减
            } else if (nums[i - 1] - 1 == nums[i]) {
                if (orientation == UP) {
                    start = i - 1;
                }
                orientation = DOWN;
                int total = 0;
                for (int j = start; j <= i; j++) {
                    total += nums[j];
                    if (total >= s) {
                        min_subarray_len = min(min_subarray_len, j - start + 1);
                    }
                }
            } else {
                start = i;
            }
        }
        return min_subarray_len == nums.size() + 1 ? 0 : min_subarray_len;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solu;
    vector<int> nums = {1,2,3,4,5,6};
    cout << solu.minSubArrayLen(7, nums);
    return 0;
}