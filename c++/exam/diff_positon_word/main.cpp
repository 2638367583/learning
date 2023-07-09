/*
    给定连个字符串s和t,编写一个函数来判断t是否是s的字母异位词
    示例1
    输入：s = "anagram", t = "nagaram"
    输出：true
    示例2
    输入：s = "rat", t = "car"
    输出：false
 */

#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class LowerException : public exception {
public:
    LowerException(string str) {
        cout << str << endl;
    }

};


class Solution
{
public:
    bool isDiffPosiWord(string str1, string str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        vector<int> vec(26, 0);

        for (int i = 0; i < str1.size(); i++) {
            if (!islower(str1.at(i)) || !islower(str2.at(i)))  {
                throw LowerException("is lower exception!");
            }
            vec[str1[i] - 'a']++;
            vec[str2[i] - 'a']--;
        }

        for (auto count : vec) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaraM";
    Solution solu;
    try {
        cout << (solu.isDiffPosiWord(s, t) ? "true" : "false");
    } catch(LowerException e){
        cout << e.what();
    }

    return 0;
}