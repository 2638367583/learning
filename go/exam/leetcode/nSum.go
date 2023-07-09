package main

import (
	"fmt"
	"sort"
)

func main() {
	test1 := []int{3, 3, 7, 7, 8, 2, 1, 2, 7, 8, 9, 0, 1, 1, 1}
	target1 := 10
	fmt.Println(threeSum(test1, target1))
	sort.Ints(test1)
	fmt.Println(nSum(test1, 0, 6, target1))
}

func nSum(nums []int, start int, n int, target int) [][]int {
	result := [][]int{}
	if n < 2 || len(nums) < n {
		return result
	}
	if n == 2 {
		left, right := start, len(nums)-1
		for left < right {
			lVal := nums[left]
			rVal := nums[right]
			if lVal+rVal == target {
				result = append(result, []int{lVal, rVal})
				for left < right && lVal == nums[left] {
					left++
				}
				for left < right && rVal == nums[right] {
					right--
				}
			} else if lVal+rVal < target {
				for left < right && lVal == nums[left] {
					left++
				}
			} else {
				for left < right && rVal == nums[right] {
					right--
				}
			}
		}
	} else {
		for i := start; i < len(nums); i++ {
			tuple := nSum(nums, i+1, n-1, target-nums[i])
			for _, v := range tuple {
				result = append(result, append([]int{nums[i]}, v...))
			}
			val := nums[i]
			for i < len(nums) && nums[i] == val {
				i++
			}
		}
	}
	return result
}

func threeSum(nums []int, target int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		tuple := twoSum(nums, i+1, target-nums[i])
		for _, v := range tuple {
			result = append(result, append([]int{nums[i]}, v...))
		}
		tmp := nums[i]
		for i < len(nums) && nums[i] == tmp {
			i++
		}
	}
	return result
}

func twoSum(nums []int, start int, target int) [][]int {
	result := [][]int{}
	//sort.Ints(nums)
	left, right := start, len(nums)-1
	for left < right {
		lv, rv := nums[left], nums[right]
		if lv+rv == target {
			result = append(result, []int{lv, rv})
			for nums[left] == lv && left < right {
				left++
			}
			for nums[right] == rv && left < right {
				right--
			}
		} else if nums[left]+nums[right] < target {
			for nums[left] == lv && left < right {
				left++
			}
		} else {
			for nums[right] == rv && left < right {
				right--
			}
		}
	}
	return result
}
