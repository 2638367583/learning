/*
    根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

    例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

    提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/daily-temperatures
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> temperStack;
        for (int i = 0; i < T.size(); i++) {
            if (temperStack.empty()) {
                temperStack.push(i);
                continue;
            }

            //当前元素大于栈顶元素则计算上升的天数
            auto index = temperStack.top();
            if (T.at(i) > T.at(index)) {
                //计算升温的天数
                result[index] = i - index;

                //出栈
                temperStack.pop();

                //i--的目的是为了让当前元素在于栈顶元素对比
                i--;

                //如果当前温度小于栈顶温度，则入栈
            } else {
                temperStack.push(i);
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    /**
     * [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
     */
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution solu;
    solu.dailyTemperatures(temperatures);

    return 0;
}