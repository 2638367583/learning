#include <iostream>

using namespace std;
class Solution {
public:
    string makeGood(string s) {
        string ans = s;
        const int postion = 'A' - 'a';
        int i = 0;
        int len = ans.size() - 1;
        while (i < len) {
            if (ans[i] == ans[i + 1] - postion
                || ans[i] == ans[i + 1] + postion) {
                ans.erase(ans.begin() + i, ans.begin() + i + 2);
                i = (i == 0 ? i - 1: i - 2);
            }
            i++;
            len = ans.size() - 1;
        }
        return ans;
    }
};

int main() {
    Solution solu;
    cout << solu.makeGood("abBAcC");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}