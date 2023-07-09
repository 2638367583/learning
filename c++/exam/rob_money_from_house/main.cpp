#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int totalMonery = 0;
    void getMoneryFromHouse(vector<int> &nums, int index, int myMonery) {
        if (index >= nums.size()) {
            return ;
        }

        int total = myMonery + nums[index];
        if (total > totalMonery) {
            totalMonery = total;
        }
        getMoneryFromHouse(nums, index + 2, total);
        getMoneryFromHouse(nums, index + 2, myMonery);
    }

    int rob(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            getMoneryFromHouse(nums, i, 0);
        }
        return totalMonery;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution solu;
    vector<int> vec = {1, 2, 3, 1};
    cout << solu.rob(vec);

    return 0;
}