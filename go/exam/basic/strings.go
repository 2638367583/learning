/*
 * @Descripttion:字符串操作
 * @Author: lly
 * @Date: 2020-08-31 01:40:25
 * @LastEditors: lly
 * @LastEditTime: 2020-11-22 01:09:52
 */
package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println("hello go")

	//求字符串的长度
	s1 := "hello"
	s2 := "hello你好"
	fmt.Println("s1 length:", len(s1))
	fmt.Println("s2 length:", len(s2))

	//拼接字符串
	fmt.Println(s1 + s2)
	s3 := fmt.Sprintf("%s - %s", s1, s2)
	fmt.Println("s3 :", s3)

	//字符串分割
	s4 := "how do you do"
	fmt.Println("split: ", strings.Split(s4, " "))
	fmt.Printf("%T\n", strings.Split(s4, " "))

	//字符串包含
	s5 := "how are you ?&"
	fmt.Println(strings.Contains(s5, "are"))
	if strings.Contains(s5, "?") {
		fmt.Println("s5 ? is index at: ", strings.LastIndex(s5, "?"))
		fmt.Println("s5 ? is index at: ", strings.Index(s5, "?"))
		fmt.Println("s5 total len: ", len(s5))
	}
	if strings.ContainsAny(s5, "%`!$&*\"'") {
		fmt.Println("s5 contain %`!$&*\"'")
	}

	//字符串比较
	s6 := "how"
	s7 := "how"
	if s6 == s7 {
		fmt.Println("s6 == s7")
	}

	//字符串前后缀
	s8 := "how do you do"
	fmt.Println("s8 prefix is how: ", strings.HasPrefix(s8, "how"))
	fmt.Println("s8 suffix is do: ", strings.HasSuffix(s8, "do"))

	//字符比较
	s9 := "abcdefg"
	s10 := "mnkk"
	fmt.Printf("%c\n", s9[0]+1)
	fmt.Println(s10[0])
	if s9[1] == s9[0]+1 {
		fmt.Println("ok")
	}

	s11 := make([]string, 5)
	fmt.Println(len(s11))

}
