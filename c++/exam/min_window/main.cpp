#include <iostream>
#include <unordered_map>
/*
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
链接：https://leetcode-cn.com/problems/minimum-window-substring/solution/c-unordered_map-8ms-9847-by-karlzhang/
来源：力扣（LeetCode）*/
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s == "" || t == "") {
            return "";
        }

        unordered_map<char, int> t_map;
        for (auto c : t) t_map[c]++;
        int left = 0;
        int max_len = s.size() + 1;
        int cnt = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (--t_map[s[i]] >=0 ) cnt++;

            while (cnt == t.size()) {

                if (max_len > i - left + 1) {
                    max_len = i - left + 1;
                    start = left;
                }

                if (++t_map[s[left]] > 0) cnt--;
                left++;
            }

        }
        return max_len == (s.size() + 1) ? "" : s.substr(start, max_len);
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solu;
    cout << solu.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}