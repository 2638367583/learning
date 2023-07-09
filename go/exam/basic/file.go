package main

import (
	"fmt"
	"os"
	"syscall"
)

func main() {
	f, err := os.OpenFile("./test.txt", os.O_RDWR, 0600) // nolint
	if err != nil {
		fmt.Print("a")
		return
	}
	syscall.Mmap()
	defer f.Close() // nolint

	if _, err = f.WriteAt([]byte("15test"+"\n"), 0); err != nil {
		panic(err)
	}

}
