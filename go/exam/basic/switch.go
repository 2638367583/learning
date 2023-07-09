/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-02 23:30:35
 * @LastEditors: lly
 * @LastEditTime: 2020-09-02 23:48:48
 */
package main

import "fmt"

func main() {
	finger := 3
	switch finger {
	case 1:
		fmt.Println("大拇指")
	case 2:
		fmt.Println("实质")
	case 3:
		fmt.Println("中指")
	case 4:
		fmt.Println("无名指")
	case 5:
		fmt.Println("小拇指")
	default:
		fmt.Println("其他")
	}

	//一次判断多个值
	num := 5
	switch num {
	case 1, 3, 5, 7, 9:
		fmt.Println("奇数")
	case 2, 4, 6, 8:
		fmt.Println("偶数")
	}

	//3.case中使用表达式
	age := 30
	switch {
	case age > 18:
		fmt.Println("澳门赌场开业")
	case age < 18:
		fmt.Println("warning")
	default:
		fmt.Println("defaut")

	}

	//4.跳出多层循环
BREAKDEMO1:
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if j == 2 {
				break BREAKDEMO1
			}
			fmt.Printf("%v-%v\n", i, j)
		}
	}
	fmt.Println("...")

	//5.99乘法表
	for i := 9; i > 0; i-- {
		for j := i; j < 10; j++ {
			fmt.Printf("%d x %d = %2d ", i, j, i*j)
		}
		fmt.Println("\n")
	}
}
