/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-08-30 21:07:09
 * @LastEditors: lly
 * @LastEditTime: 2020-08-31 01:37:30
 */
package main

import (
	"fmt"
	"math"
)

//int type
var x8 int8 = math.MaxInt8
var x64 int64 = math.MaxInt64

//float type
var f32 float32 = math.MaxFloat32
var f64 float64 = math.MaxFloat64

//bool type
var b1 bool = true
var b2 = false

//string
var str1 = "hello go"
var str2 = "你好，go"
var mstr1 = `hello
go
hello
go
\t\n
\n
`

func main() {
	fmt.Println("hello go!")

	fmt.Println("max int8:", x8)
	fmt.Println("max int64:", x64)

	fmt.Println("max float32:", f32)
	fmt.Println("max float64:", f64)

	fmt.Println("bool b1:", b1)
	fmt.Println("bool b2:", b2)

	fmt.Printf("%s\n", str1)
	fmt.Printf("%s\n", str2)
	fmt.Printf("%s\n", mstr1)
}
