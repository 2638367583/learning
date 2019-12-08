/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned long len = s.length();
        set<char> cSet;
        int sum= 0;
        int i = 0, j = 0;
        while (i < len && j < len) {
            if (!contain(cSet, s.at(j))) {
                cSet.insert(s.at(j++));
                sum = max(j-i, sum);

            } else {
                cSet.erase(s.at(i++));
            }
        }
        return sum;
    }

private:
    bool contain(set<char> cSet, char s) {
        for (auto iter = cSet.begin(); iter != cSet.end(); ++iter) {
            if (s == *iter) {
                return true;
            }
        }
        return false;
    }
};

//return    i     J
//a b c a b c b b
//0 1 2 3 4 5 6 7
//i i j
//p w w k e w
//0 1 2 3 4 5
int main() {
    Solution solu;
    int sum = solu.lengthOfLongestSubstring("abcabcbb");
    std::cout << sum << std::endl;
    int sum2 = solu.lengthOfLongestSubstring("bbbbb");
    std::cout << sum2 << std::endl;
    int sum3= solu.lengthOfLongestSubstring("pwwkew");
    std::cout << sum3 << std::endl;
    int sum4= solu.lengthOfLongestSubstring("a");
    std::cout << sum4 << std::endl;
    return 0;
}