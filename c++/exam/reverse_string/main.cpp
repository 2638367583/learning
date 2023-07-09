#include <iostream>
#include <string>

/**
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

    示例 1:

    输入: "Let's take LeetCode contest"
    输出: "s'teL ekat edoCteeL tsetnoc" 
    注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
 */
using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end) {
        while(start < end) {
            s[start]   ^= s[end];
            s[end]     ^= s[start];
            s[start++] ^= s[end--];
        }
    }

    string reverseWords(string &s) {
        int index = 0;
        while(index < s.size()) {
            if (s.at(index) != ' ') {
                break;
            }
            index++;
        }
        int start = index;
        for (int i = index; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                reverse(s, start, i - 1);
                while (++i < s.size() && s.at(i) == ' ');
                start = i;
            }
        }
        reverse(s, start, s.size() - 1);
        return s;
    }

    string reverseWords2(string &s) {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    string str = "   s'teL ekat  edoCteeL tsetnoc   !";
    Solution solu;
    solu.reverseWords(str);
    cout << str;
    return 0;
}