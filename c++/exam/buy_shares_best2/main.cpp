#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int profit(vector<int> &prices, int start)
    {
        if (start >= prices.size()) {
            return 0;
        }
        int max = 0;
        for (int i = start; i < prices.size(); i++) {
            int max_profit = 0;
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[i] < prices[j]) {
                    int num = profit(prices, j + 1) + prices[j] - prices[i];
                    if (num > max_profit) {
                        max_profit = num;
                    }
                }
            }
            if (max_profit > max) {
                max = max_profit;
            }
        }
        return max;
    }
    int maxProfit(vector<int>& prices) {
        return profit(prices, 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec = {7,1,5,3,6,4};
    Solution solu;
    cout << solu.maxProfit(vec);

    return 0;
}