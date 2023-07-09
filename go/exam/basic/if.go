/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-02 23:17:53
 * @LastEditors: lly
 * @LastEditTime: 2020-09-02 23:23:24
 */
package main

import "fmt"

func main() {
	var score = 65
	if score >= 90 {
		fmt.Println("A")
	} else if score >= 75 {
		fmt.Println("B")
	} else {
		fmt.Println("C")
	}

	if score1 := 65; score1 >= 90 {
		fmt.Println("A")
	} else if score1 >= 75 {
		fmt.Println("B")
	} else {
		fmt.Println("C")
	}

}
