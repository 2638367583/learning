#include <iostream>
#include <vector>
/**
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

L     D      R
E   O E    I I
E  C  I   H  N
T A   S A    G
A     A
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
// 0 - 4 - 8       3    2n   2n-2
// 1 - 3 - 5
// 2 - 6 - 12
//
// 0 - 6 - 12      4    2n   2n-2
// 1 - 5 - 7 - 11 - 13
//
// 0 - 8 - 16      5    2n   2n-2
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int j = 0;
        int len = 0;
        vector<string> str_arr(4, "");

        while (len < s.size()) {
            for (int i = 0; i < numRows; i++) {
                if (len >= s.size()) break;
                str_arr.at(i) += s[len++];
            }

            for (int i = numRows - 2; i > 0; i--) {
                if (len >= s.size()) break;
                str_arr[i] += s[len++];
            }
        }

        for (int i = 0; i < numRows; i++) {
            result += str_arr[i];
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solu;
    string str = "LEETCODEISHIRING";
    cout << solu.convert(str, 4);
    return 0;
}