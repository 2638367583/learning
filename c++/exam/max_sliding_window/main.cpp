#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    void entry_queue(deque<int> &deq, vector<int> &nums, int index) {
        if (deq.empty()) {
            deq.push_back(index);
            return;
        }

        //小于队尾值就入队尾
        do {
            if (nums.at(index) >= nums.at(deq.front()) || nums.at(index) >= nums.at(deq.back())) {
                deq.pop_back();
            } else {
                break;
            }
        } while (!deq.empty());

        deq.push_back(index);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = k - 1;
        deque<int> index_deque;
        vector<int> result;

        for (int i = left; i < right; i++) {
            entry_queue(index_deque, nums, i);
        }

        for (int i = 0; i < nums.size() - k + 1; i++) {

            entry_queue(index_deque, nums, right);

            //取队头元素
            while(!index_deque.empty()) {
                int index = index_deque.front();
                if (right - index > k-1) {
                    index_deque.pop_front();
                } else {
                    result.push_back(nums.at(index));
                    break;
                }
            }

            right++;
        }
        return result;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
//    vector<int> vec = {1,-1};
//        vector<int> vec = {7, 2, 4};

    Solution solu;
    solu.maxSlidingWindow(vec, 3);
    return 0;
}