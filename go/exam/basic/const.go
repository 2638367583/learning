/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-08-28 21:18:17
 * @LastEditors: lly
 * @LastEditTime: 2020-08-30 11:52:08
 */
package main

import (
	"fmt"
)

//变量
var x = 100
var y = 100
var f float32 = 2

var (
	host   string = "127.0.0.1"
	port   int16  = 3306
	name   string = "root"
	passwd string = "abc123"
)

//常量
const pi = 3.14157

const (
	p2 = 3.131
	e  = 2.7
)

const (
	n1 = 10
	n2
	n3
)

const (
	i1 = iota
	i2
	i3
)

func main() {
	name1 := "hty"
	fmt.Println("hello go !")
	fmt.Println("host: ", host)
	fmt.Println("port: ", port)
	fmt.Println("name: ", port)
	fmt.Println("passwd: ", "******")
	fmt.Println("f:", f)
	fmt.Println("name", name1)
	fmt.Println("x: ", x)
	fmt.Println("y: ", y)
	fmt.Println("pi: ", pi)
	fmt.Println("e: ", e)
	fmt.Println("n1: ", n1)
	fmt.Println("n2: ", n2)
	fmt.Println("n3: ", n3)
	fmt.Println("i1: ", i1)
	fmt.Println("i2: ", i2)
	fmt.Println("i3: ", i3)
	fmt.Println("%", 38%27)
}
