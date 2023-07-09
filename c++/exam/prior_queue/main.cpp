#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
/*
LeetCode 第 347 题：给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。

你的算法的时间复杂度必须优于 O(nlogn) ，n 是数组的大小

示例：car，car，book，desk，desk，desk*/
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<int> result;

        for (auto n : nums) {
            if (freqMap.find(n) != freqMap.end()) {
                freqMap[n]++;
            } else {
                freqMap.insert(make_pair(n, 1));
            }
        }

        priority_queue<pair<int, int> >pri_queue;
        auto iter = freqMap.begin();
        while (iter != freqMap.end()) {
            pri_queue.push(make_pair(iter->second, iter->first));
            iter++;
        }

        while (!pri_queue.empty() && k--) {
            result.push_back(pri_queue.top().second);
            pri_queue.pop();
        }
        return vector<int>();
    }
};

int main() {
//    unordered_map<string, int>
//    priority_queue< pair<string, int>, unordered_map<string, int> > a;
//
//    for (int i = 0; i < 5; i++) {
//
//        a.push(i);
//
//    }

    Solution solu;
    vector<int> vec{3, 3, 3, 4, 4, 1};
    solu.topKFrequent(vec, 3);

//    cout << a.top() << endl;
//    a.pop();
//    cout << a.top() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}