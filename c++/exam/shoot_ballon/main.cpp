#include <iostream>
#include <vector>
#include <map>
/**
 * 输入：
 * 12 5
 * 2 5 3 1 3 2 4 1 0 5 4 3
 */


 using namespace std;

 bool isFull(const vector<int> array) {
     for (auto v : array) {
         if (v <= 0)
             return false;
     }
     return true;
 }

 int shoot_ballon(vector<int> array, int n, int m)
 {
    int start = 0;
    int min_num = n + 1;
    vector<int> vec(m, 0);

     for (int i = 0; i < array.size(); i++) {
         //没有打到球，不做任何操作
         if (array[i] == 0) continue;
         //打到颜射球，存储各种颜射打到的次数
         vec[array[i] - 1]++;

         //判断是否所有颜射都已经存满，如果start下标的颜射球超过1
         //那么我们就不断start++，直到start不超过1
         if (isFull(vec)) {
             while (array.at(start) == 0
                    || vec.at(array[start] - 1) > 1) {
                 if (array[start] != 0)
                    vec[array[start] - 1]--;
                 start++;
             }
             min_num = min(min_num, i - start + 1);
         }
    }
    return min_num == (n + 1) ? -1 : min_num;
 }
 int main() {
    vector<int> array = {2,5,3,1,3,2,4,1,0,5,4,3};
    vector<int> array1 = {0,5,3,1,3,0,4,1,0,5,4,3};
    cout << shoot_ballon(array1, 12, 5) << endl;
    return 0;
}