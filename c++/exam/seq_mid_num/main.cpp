/**
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
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int rIndex = (len1 + len2) / 2;
        int lIndex = (len1 + len2 - 1) / 2;

        int i = 0, j = 0;
        int count = 0;
        int lValue = 0;
        int rValue = 0;
        while (i<len1 && j<len2) {
            int min = 0;
            if (nums1.at(i) >= nums2.at(j)) {
                min = nums2.at(j);
                j++;
            } else {
                min = nums1.at(i);
                i++;
            }
            if (count  == lIndex) {
                lValue = min;
            }
            if (count == rIndex) {
                rValue = min;
                break;
            }
            count++;
        }

        if (count != rIndex) {
            if (i >= len1) {
                while (j < len2) {
                    
                    j++;
                }
            }
        }
        return (lValue + rValue) / 2.0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solu;
    vector<int> v1 = {0};
    vector<int> v2 = {1,2,3,4};
    cout << solu.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}