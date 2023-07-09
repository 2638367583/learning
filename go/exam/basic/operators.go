/*
 * @Descripttion: go运算符
 * @Author: lly
 * @Date: 2020-09-02 21:19:45
 * @LastEditors: lly
 * @LastEditTime: 2020-09-02 21:41:14
 */
package main

import "fmt"

func main() {
	//1.算术运算符
	a := 10
	b := 20
	fmt.Println(a + b)
	fmt.Println(a - b)
	fmt.Println(a * b)
	fmt.Println(b / a)
	fmt.Println(5 % 2)
	a++
	fmt.Println(a)
	a--
	fmt.Println(a)

	//2.关系运算符
	fmt.Println(a == 10)
	fmt.Println(a != 10)
	fmt.Println(a >= 10)

	//3.逻辑运算符
	fmt.Println(10 > 5 && 1 == 1)
	fmt.Println(!(10 > 5))
	fmt.Println(1 > 5 || 1 == 1)

	//4.位运算
	c := 1               //001
	d := 5               //101
	fmt.Println(c & d)   //001  1
	fmt.Println(c | d)   //101  5
	fmt.Println(c ^ d)   //100  4
	fmt.Println(1 << 2)  //100  4
	fmt.Println(4 >> 2)  //001  1
	fmt.Println(1 << 10) //1024

	//5.赋值运算符
	f := 5
	f += 5
	fmt.Println(f)
	f -= 5
	fmt.Println(f)
}
