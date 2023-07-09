package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int, 0)

	defer func() {
		recover()
		fmt.Println("aaa")
	}()

	ch <- 1
	//go func() {
	//	ch <- 1
	//}()

	time.Sleep(1 * time.Second)

	close(ch)
	//ch <- 1

	//fmt.Println(<-ch)
	fmt.Println(<-ch)
	//for c := range ch {
	//	fmt.Println(c)
	//}

}
