package main

import (
	"fmt"
	"sort"
)

/*
求前k个高频的元素，按频次从高到低输出
输入: [1,6,5,5,5,6,3,4,4,8] k=3
输出: [5,6,4]
*/

//0-100
//
//100000
//
//100
//
//[100]int{}
//
//0 , 1 , 2, 3, 4, 5
//0   1   0   1 2  2

func main() {
	nums := []int{1, 6, 5, 5, 5, 6, 3, 4, 4, 8}
	//[5 5 5 6 6 4 4 1 3 8]

	//nums1 := []int{1, 6, 5}
	//nums2 := []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	//nums3 := []int{}
	//nums4 := []int{-10, -6, 5, -5, -5, 111111111, 3, -99999999, 4, 8}
	fmt.Println(repeatTopN(nums, 3))
	//fmt.Println(repeatTopN(nums1, 2))
	//fmt.Println(repeatTopN(nums2, 5))
	//fmt.Println(repeatTopN(nums3, 3))
	//fmt.Println(repeatTopN(nums4, 5))
	//fmt.Println(repeatTopN(nums4, -5))
}

//o(n)
//o(n + n * n) n2

func repeatTopN(nums []int, k int) []int {
	if k > len(nums) {
		return []int{}
	}
	result := []int{}
	numMap := map[int]int{}
	for _, num := range nums {
		numMap[num]++
	}

	sort.Slice(nums, func(i, j int) bool {
		return numMap[nums[i]] > numMap[nums[j]]
	})
	//o(n*logn)

	count := 1
	val := nums[0]
	result = append(result, val)
	for i := 0; i < len(nums); i++ {
		if val != nums[i] {
			val = nums[i]
			result = append(result, val)
			count++
		}
		if count > k-1 {
			break
		}
	}
	//result = nums

	//n *log(n)

	//for i := 0; i < k; i++ {
	//maxVal := math.MinInt32
	//maxCount := math.MinInt32
	//for num, count := range numMap {
	//	if count > maxCount {
	//		maxCount = count
	//		maxVal = num
	//	}
	//}
	//delete(numMap, maxVal)
	//if maxVal != math.MinInt32 {
	//	result = append(result, maxVal)
	//}
	//}

	return result
}
