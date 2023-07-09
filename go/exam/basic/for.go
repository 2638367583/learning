/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-02 23:23:14
 * @LastEditors: lly
 * @LastEditTime: 2020-09-02 23:29:29
 */
package main

import "fmt"

func main() {
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}

	//2.省略初始语句，但是必须保留初始语句后面的分号
	var i = 0
	for ; i < 10; i++ {
		fmt.Println(i)
	}

	//3.省略初始语句和结束语句
	var j = 10
	for j > 0 {
		fmt.Println(j)
		j--
	}

	//4.无限循环o
	for {
		fmt.Println("无限循环")
	}

	//5.brake 跳出for循环
	for i := 0; i < 5; i++ {
		fmt.Println(i)
		if i == 3 {
			break
		}
	}

	//6.contine继续循环
	for i := 0; i < 5; i++ {
		if i == 3 {
			continue
		}
		fmt.Println(i)
	}

}
