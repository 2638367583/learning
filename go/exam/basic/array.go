/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-03 00:07:41
 * @LastEditors: lly
 * @LastEditTime: 2020-09-03 00:37:03
 */
package main

import "fmt"

func main() {
	var a [3]int
	var b [4]int
	fmt.Println(a)
	fmt.Println(b)

	//数组的初始化
	//1.定义时使用初始化列表的方式初始化
	var cityArray = [4]string{"北京", "上海", "广州", "深圳"}
	fmt.Println(cityArray)

	//2.编译推导数组长度
	var boolArray = [...]bool{true, false, false, true}
	fmt.Println(boolArray)

	//3.使用索引值的方式初始化
	var langArray = [...]string{1: "Golang", 3: "Python", 7: "Java"}
	fmt.Println(langArray)
	fmt.Printf("%T\n", langArray)

	//数组的遍历
	//1.for循环
	for i := 0; i < len(cityArray); i++ {
		fmt.Println(cityArray[i])
	}

	//2.for range遍历
	for _, value := range cityArray {
		fmt.Println(value)
	}

	//二维数组
	//mulCityArray := [...][2]string{
	mulCityArray := [3][2]string{
		{"上海", "shanghai"},
		{"北京", "beijing"},
		{"重庆", "chongqing"},
	}
	fmt.Println(mulCityArray)
	fmt.Println(mulCityArray[2][1])

	//二维数组遍历
	for _, v1 := range mulCityArray {
		//fmt.Println(v1)
		for _, v2 := range v1 {
			fmt.Println(v2)
		}
	}

	//数组是值的类型
	x := [3][2]int{
		{1, 2},
		{2, 3},
		{3, 4},
	}
	fmt.Println(x)
	f1(x)
	y := x
	y[0][0] = 100
	fmt.Println(x)

	//求数组[1, 3, 5, 7, 8]所有元素的和
	a1 := [5]int{1, 3, 5, 7, 8}
	sum := 0
	for _, v := range a1 {
		sum += v
	}
	fmt.Println("sum = ", sum)

	//找出数组中和为指定值的两个元素的下标，比如从数组[1, 3, 5, 7, 8]中找出和为8的两个元素的下标分别为(0,3)和(1,2)。
	thresh := 8
	for i := 0; i < len(a1); i++ {
		for j := i; j < len(a1); j++ {
			if a1[i]+a1[j] == thresh {
				fmt.Println(i, "+", j)
			}
		}
	}
}

func f1(a [3][2]int) {
	a[0][0] = 100
}
