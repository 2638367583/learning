#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
/**
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

    示例 1:

    输入:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    输出: [1,2,3,6,9,8,7,4,5]
    示例 2:

    输入:
    [
      [1, 2, 3, 4],
      [5, 6, 7, 8],
      [9,10,11,12]
    ]
    输出: [1,2,3,4,8,12,11,10,9,5,6,7]

 */
 using namespace std;

    class Solution {
    public:
        void spiralOrder(const vector<vector<int>>& matrix) {
            //制定上下左右四条边界，每边遍历一次后缩小边界
            int left = 0;
            int right = matrix[0].size()-1;
            int up = 0;
            int down = matrix.size()-1;

            while (true) {
                for (int i = left; i <= right; i++) {
                    cout << matrix[up][i];
                }
                if (++up > down) break;

                for (int i = up; i <= down; i++) {
                    cout << matrix[i][right];
                }

                if (--right <left) break;
                for (int i = right; i >= left; --i) {
                    cout << matrix[down][i];
                }
                if (--down < up) break;


                for (int i = down; i >= up; --i) {
                    cout << matrix[i][left];
                }

                if (++left > right) break;
            }
        }
    };

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> matrix = {  {1, 2, 3,4,4},
                                    {4, 5, 6,4,5},
                                    {7, 8, 9,5,5},
                                    {7, 8, 9,5,5}};
    Solution solu;
    solu.spiralOrder(matrix);

    return 0;
}