#include <iostream>
#include <vector>

using namespace std;

const int Mine = 9;

vector<vector<int> > mine_clearance(int n, int m, int k)
{
    //生成n * m的矩阵
    vector<vector<int> > array(n, vector<int>(m, 0));

    //设置随机种子 TODO

    while (k--) {
        //雷的坐标随机生成
        int x = 0;
        int y = 0;
        do {
            x = rand() % n;
            y = rand() % m;
        } while (array[x][y] == Mine);

        //x,y的坐标点为雷区
        array[x][y] = Mine;

        /*雷区周边坐标图
        /*
         * (x-1, y-1) (x-1, y) (x-1, y+1)
         * (x,   y-1) (x,   y) (x,   y+1)
         * (x+1, y-1) (x+1, y) (x+1, y+1)
         */

        for (int i = x - 1; i < x + 2; i++) {
            //x轴越界
            if (i < 0 || i >= n) continue;

            for (int j = y - 1; j < y + 2; j++) {
                //y轴越界
                if (j < 0 || j >= m) continue;

                //雷区跳过
                if (array[i][j] == Mine) continue;

                //非雷区+1
                array[i][j] += 1;
            }
        }
    }

    return array;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> array = mine_clearance(20, 20, 100);

    //打印雷分部
    for (auto vec : array) {
        for (auto v : vec) {
            cout << v <<" ";
        }
        cout << endl;
    }
    return 0;
}