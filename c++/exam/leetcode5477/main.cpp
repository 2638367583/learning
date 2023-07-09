#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isok(const vector<int> &arr, int n) {
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] != 0) {
                return false;
            }
            n--;
            if (n == 0) {
                break;
            }
        }
        return true;
    }
    void vec_swap(vector<vector<int>> &arr, int i, int k) {
        for (int j = i; j > k; j--) {
            //vector<int> tmp;

            arr[j].swap(arr[j-1]);

        }
    }
    int minSwaps(vector<vector<int>>& grid) {
        //2个0
        int ans = 0;
        int n = grid.size() - 1;
        int k = 0;
        int test = 0;
        while (n) {
            for (int i = k; i < grid.size(); i++) {
                if (isok(grid[i], n)) {
                    ans += i - k;
                    vec_swap(grid, i, k);
                    //grid[i].swap(grid[k]);
                    k++;
                    n--;
                    //return ans;
                    test++;
                    if (test == 2) return k;
                    break;
                }

                 //没找到return -1
                if (i == (grid.size() - 1)) {
                    return test;
                    return -1;
                }
            }
        }
        return test;
        return ans;
    }
};

int main() {
    vector<vector<int>> grid(3, vector<int>(3, 0));
    grid[0][2] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[2][0] = 1;
    Solution solu;
    solu.minSwaps(grid);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}