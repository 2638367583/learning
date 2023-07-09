/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-07 00:09:42
 * @LastEditors: lly
 * @LastEditTime: 2020-09-07 00:20:26
 */
package main

import (
	"fmt"
	"strings"
)

func main() {
	//使用map统计单词个数
	var str string = "how do you do"
	var workMap = make(map[string]int, 10)
	var strList = strings.Split(str, " ")
	for _, s := range strList {
		var _, exist = workMap[s]
		if exist {
			workMap[s]++
		} else {
			workMap[s] = 0
		}
	}

	fmt.Println(workMap)
}
