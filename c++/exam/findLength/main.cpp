#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
class Solution {
public:
    //暴力法, 时间超出限制
    int findLength1(vector<int>& A, vector<int>& B) {
        int max_len = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                int k = 0;
                if (A[i] == B[j]) {
                    while(i + k < A.size() && j + k < B.size() && A[i + k] == B[j + k]) {
                        k++;
                    }
                    max_len = max(k, max_len);
                }
            }
        }
        return max_len;
    }

    //暴力 + 哈希
    int findLength2(vector<int>& A, vector<int>& B) {
        unordered_map<int, list<int>> bArrayMap;
        int max_len = 0;

        for (int i = 0; i < B.size(); i++) {
            bArrayMap[B[i]].push_back(i);
        }

        for (int i = 0; i < A.size(); i++) {
            for (auto index : bArrayMap[A[i]]) {
                int k = 0;
                while(i + k < A.size() && index + k < B.size() && A[i + k] == B[index + k]) {
                    k++;
                }
                max_len = max(k, max_len);
            }
        }

        return max_len;
    }

    //二分查找
    bool check(int len, vector<int> &A, vector<int> &B) {
        list<string> strList;
        for (int i = 0; i < A.size(); i++) {
            string str = "";
            for (int j = i; len + i <= A.size() && j < len + i; j++) {
                str += A[j];
            }
            if (str != "") {
                strList.push_back(str);
            }
        }

        for (int i = 0; i < B.size(); i++) {
            string str;
            for (int j = i; i + len <= B.size() && j < len + i; j++) {
                str += B[j];
            }
            for (auto iter = strList.begin(); iter != strList.end(); ++iter) {
                if (*iter == str) {
                    return true;
                }
            }
        }
        return false;
    }

    int findLength3(vector<int>& A, vector<int>& B) {
        int lo = 0, hi = min(A.size(),A.size()) + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, A, B)) lo = mid + 1;
            else hi = mid;
        }
        return lo == 0 ? lo : lo - 1;
    }

    //动态规划
    int findLength4(vector<int> &A, vector<int> &B) {
        int ans = 0;
        vector<vector<int> > arr(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = B.size() - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    arr[i][j] = arr[i + 1][j + 1] + 1;
                    if (ans < arr[i][j]) ans = arr[i][j];
                }
            }
        }
        return ans;
    }

    //直尺比对
    //参考https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/wu-li-jie-fa-by-stg-2/
    int findLength5(vector<int> &A, vector<int> &B) {

        return 0;
    }

    //二分 + 哈希 + Rabin-Karp算法
    int findLength6(vector<int> &A, vector<int> &B) {

        return 0;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    /*
     * 输入:
        A: [1,2,3,2,1]
        B: [3,2,1,4,7]
        输出: 3
     */
//    vector<int> v1{1, 2, 3, 2, 1};
//    vector<int> v2{3, 2, 1, 4, 7};

    vector<int> v1{0, 0, 0, 0, 1};
    vector<int> v2{1, 0, 0, 0, 0};
    Solution solu;
    cout << solu.findLength4(v1, v2);
    return 0;
}