#include <iostream>
#include <vector>
/**
 *
    给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
    请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。
    示例 1:
    nums1 = [1, 3]
    nums2 = [2]
    则中位数是 2.0
    示例 2:
    nums1 = [1, 2]
    nums2 = [3, 4]
    则中位数是 (2 + 3)/2 = 2.5
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int i = 0 , j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                vec.push_back(nums1[i++]);
            } else {
                vec.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size()) {
            vec.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            vec.push_back(nums2[j++]);
        }

//        for (auto num :  vec) {
//            cout << num << endl;
//        }

        //获取中位数,奇数的情况下也取两个相同的数和偶数计算统一
        return (vec.at((vec.size() - 1) / 2) + vec.at(vec.size() / 2)) * 0.5;
    }

    int findMedian(vector<int>& nums1, int len1,  vector<int>& nums2, int len2, int k) {
        if (k == 1) {
            if (len1 >= nums1.size()) {
                return nums2.at(len2);
            }

            if (len2 >= nums2.size()) {
                return nums1.at(len1);
            }

            if (nums1.at(len1) < nums2.at(len2)) {
                return nums1.at(len1);
            } else {
                return nums2.at(len2);
            }
        }

        int mid = k / 2;

        if (len1 + mid - 1 >= nums1.size()) {
            return nums2.at(len2 + k - 1);
        }
        if (len2 + mid - 1 >= nums2.size()) {
            return nums1.at(len1 + k - 1);
        }

        if (nums1.at(len1 + mid - 1) < nums2.at(len2 + mid - 1)) {
            len1 = len1 + mid;
        } else {
            len2 = len2 + mid;
        }

        k -= mid;

        return findMedian(nums1, len1, nums2, len2, k);
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int firstMid  = (nums1.size() + nums2.size() + 1) / 2;
        int secondMid = (nums1.size() + nums2.size() + 2) / 2;

        return (findMedian(nums1, 0, nums2, 0, firstMid) + findMedian(nums1, 0, nums2, 0, secondMid)) * 0.5f;
    }
};

int main() {
//    vector<int> vec1 = {1, 2, 4, 5};
//    vector<int> vec2 = {0, 2, 6, 8};

//    vector<int> vec1 = {1, 2, 4, 5};
//    vector<int> vec2 = {0};

    vector<int> vec1 = {-1};
    vector<int> vec2 = {0, 1, 2};

    Solution solu;

//    cout << solu.findMedianSortedArrays(vec1, vec2);
    cout << solu.findMedianSortedArrays2(vec1, vec2);

}