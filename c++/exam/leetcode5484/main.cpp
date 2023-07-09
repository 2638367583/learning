#include <iostream>

using namespace std;
class Solution {
public:
    string &invert(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                s[i] = '0';
            else if (s[i] == '0')
                s[i] = '1';
        }
        return s;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        while (k >= s.size() && n--) {
            string si = s;
            s = si + "1";
            invert(si);
            reverse(si.begin(), si.end());
            s += si;
        }
        return s[k-1];
    }
};

int main() {
    Solution solu;
    solu.findKthBit(4, 11);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}