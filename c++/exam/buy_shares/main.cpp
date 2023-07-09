#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int buy_shares_best(const vector<int> &shares_price_tab) {
        int max_income = 0;
        for (int i = 0; i < shares_price_tab.size(); i++) {
            for (int j = i + 1; j < shares_price_tab.size(); j++) {
                if (shares_price_tab.at(j) - shares_price_tab.at(i) > max_income) {
                    max_income = shares_price_tab.at(j) - shares_price_tab.at(i);
                }
            }
        }
        return max_income;
    }

    int arr_max_index(vector<int>vec, int start) {
        int max_index = start;
        for (int i = start; i < vec.size(); i++) {
            if (vec.at(max_index) < vec.at(i)) {
                max_index = i;
            }
        }
        return max_index;
    }

    int buy_shares_best2(const vector<int> &shares_price_tab) {
        //当前日期对应的最大值的index
        vector<int> max_income_array(shares_price_tab.size());

        //获取每个元素对应的最大值
        int index = arr_max_index(shares_price_tab, 0);
        for (int i = 0; i < shares_price_tab.size(); i++) {
            if (index <= i) {
                index = arr_max_index(shares_price_tab, i);
            }
            max_income_array[i] = index;
        }

        //获取利润的最大值
        int max_income = shares_price_tab.at(max_income_array.at(0)) - shares_price_tab.at(0);
        for (int i = 0; i < shares_price_tab.size(); i++) {
            if (shares_price_tab.at(max_income_array.at(i)) - shares_price_tab.at(i) > max_income) {
                max_income = shares_price_tab.at(max_income_array.at(i)) - shares_price_tab.at(i);
            }
        }

        return max_income;
    }

    int buy_shares_best3(const vector<int> &shares_price_tab) {
        int max_profit= 0;
        int min_price = 1e9;
        for (int price : shares_price_tab) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> shares_price_tab = {7, 1, 5, 3, 6, 4};
//    vector<int> shares_price_tab1 = {6, 5, 4, 3, 2, 1};
    Solution solu;
//    cout << solu.buy_shares_best(shares_price_tab1);
//    cout << solu.buy_shares_best2(shares_price_tab1);
    cout << solu.buy_shares_best3(shares_price_tab);


    return 0;
}