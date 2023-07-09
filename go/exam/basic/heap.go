package main

import (
	"container/heap"
	"fmt"
)

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := h.Len()
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	ints := IntHeap{}
	heap.Init(&ints)
	heap.Push(&ints, 2)
	heap.Push(&ints, 1)
	heap.Push(&ints, 3)
	for ints.Len() > 0 {
		fmt.Println("pop:%v", heap.Pop(&ints))
	}
}
