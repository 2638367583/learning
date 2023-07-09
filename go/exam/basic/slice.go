/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-03 16:58:24
 * @LastEditors: lly
 * @LastEditTime: 2020-11-18 23:06:36
 */
package main

import (
	"fmt"
	"sort"
)

func main() {
	//切片
	var a []string
	var b []int

	var c = []bool{false, true}
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)

	//基于数组得到切片
	a1 := [5]int{5, 4, 3, 2, 1}
	b1 := a1[1:4]
	fmt.Println(a1)
	fmt.Println(b1)

	//切片再切片
	c1 := b1[0:len(b1)]
	fmt.Println(c1)

	//make函数构造切片
	d := make([]int, 5, 10)
	fmt.Println(d)

	//通过len函数来获取切片的长度
	fmt.Println(len(d))
	//通过cap函数获取切片的容量
	fmt.Println(cap(d))

	d = append(d, 1)
	fmt.Println(d)

	d = append(d, b1...)
	fmt.Println(d)

	//切片赋值是引用
	a2 := make([]int, 5, 10)
	b2 := a2
	b2[0] = 100
	fmt.Println(a2)
	fmt.Println(b2)

	//切片遍历
	for i := 0; i < len(a2); i++ {
		fmt.Println(a2[i])
	}

	for _, v := range a2 {
		fmt.Println(v)
	}

	//使用copy复制切片
	a3 := make([]int, 5, 6)
	copy(a3, a2)
	a3[4] = 100
	fmt.Println(a3)
	fmt.Println(a2)

	//删除元素
	a3[1] = 110
	//a3 = [100, 0, 0, 0, 100]

	a3 = append(a3[:1], a3[2:]...)
	fmt.Println(a3)

	/*
		1.请写出下面代码的输出结果。
		func main() {
			var a = make([]string, 5, 10)
			for i := 0; i < 10; i++ {
				a = append(a, fmt.Sprintf("%v", i))
			}
			fmt.Println(a)
		}
	*/
	var a4 = make([]string, 5, 10)
	for i := 0; i < 10; i++ {
		a4 = append(a4, fmt.Sprintf("%v", i))
	}
	fmt.Println(a4)

	/*
		2.请使用内置的sort包对数组var a = [...]int{3, 7, 8, 9, 1}进行排序（附加题，自行查资料解答）。
	*/
	sort.Sort(sort.IntSlice(a3))
	fmt.Println(a3)
	sort.Sort(sort.Reverse(sort.IntSlice(a3)))
	fmt.Println(a3)

	test105 := []int{1, 2, 3, 4}
	fmt.Println(test105[0:len(test105)])
}
