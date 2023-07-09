/*
 * @Descripttion:
 * @Author: lly
 * @Date: 2020-09-13 15:40:21
 * @LastEditors: lly
 * @LastEditTime: 2021-03-20 14:59:01
 */
package main

import (
	"fmt"
	"reflect"
)

func reflectType(x interface{}) {
	v := reflect.TypeOf(x)
	fmt.Printf("type:%v\n", v)
	fmt.Println(v)
	a := reflect.TypeOf(x)
	fmt.Println(a.Field(0))
	var b  a.Field(0)
	fmt.Println(b)
}
type Test struct {
		a string 
		b int
	}
func main() {
	
	test := Test{}
	//var a float32 = 3.14
	//reflectType(a) // type:float32
	//var b int64 = 100
	//reflectType(b) // type:int64
	reflectType(test) // type:int64
}
