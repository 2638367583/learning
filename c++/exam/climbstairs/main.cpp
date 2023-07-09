#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_count = 0;
        string result;
        for (int i = 1; i < s.size() - 1; i++) {
            int start = 0;
            int end = 0;

            if (s[i - 1] == s[i + 1]) {
                start = i - 1;
                end = i + 1;
            } else if (s[i] == s[i - 1]) {
                start = i - 1;
                end = i;
            } else {
                continue;
            }

            int count = 0;
            while (start) {
                if (s[start--] == s[end++]) {
                    count++;
                } else {
                    break;
                }
            }
            if (max_count < count) {
                max_count = count;
                result = s.substr(start + 1, end - start - 1);
            }
        }
        return result;
    }

};

int main() {
    Solution solu;
    cout << solu.longestPalindrome("cbbd");

    return 0;
}