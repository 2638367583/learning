#include <iostream>
#include <stack>
#include <map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;
        map<char, char> bracket_map;
        bracket_map.insert(pair<char, char>('(', ')'));
        bracket_map.insert(pair<char, char>('[', ']'));
        bracket_map.insert(pair<char, char>('{', '}'));
        for (auto c : s) {
            for (auto &kv : bracket_map) {
                //左边括号入栈
                if (kv.first == c) {
                    bracket_stack.push(c);
                    continue;
                }

                //右括号和栈顶元素做对比
                if (kv.second == c) {
                    if (bracket_stack.empty()) {
                        return false;
                    }
                    char preSymbol = bracket_stack.top();
                    bracket_stack.pop();
                    if (preSymbol != kv.first) {
                        return false;
                    }
                    break;
                }
            }
        }
        if (!bracket_stack.empty()) {
            return false;
        }

        return true;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    string str("{[(abc)]}");
    Solution solu;
    cout << (solu.isValid(str)?"true":"false");
    return 0;
}