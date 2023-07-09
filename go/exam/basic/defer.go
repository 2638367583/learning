/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-05 22:52:49
 * @LastEditors: lly
 * @LastEditTime: 2020-09-13 15:16:52
 */
package main

import "fmt"

//defer的使用
func f1() int {
	x := 5
	defer func() {
		x++
	}()
	return x
}

func f2() (x int) {
	defer func() {
		x++
	}()
	return 51
}

func f3() (y int) {
	x := 5
	defer func() {
		x++
	}()
	return x
}

func f4() (x int) {
	defer func(x int) {
		x++
	}(x)
	return 5
}

//函数声/*  */明
/*
type func(int, int)int B1Func

//闭包
for b1(x int) B1Func{
	return func(x int){
		x += 5
	}
}
*/

func main() {
	fmt.Println(f1())
	fmt.Println(f2())
	fmt.Println(f3())
	fmt.Println(f4())

	mat := [][]int{{1, 2}, {3, 4}, {5, 5}}

	fmt.Println(len(mat))
	fmt.Println(len(mat[0]))

	//	fmt.Println(b1(5))
	//fmt.Println(b1(5))
}
