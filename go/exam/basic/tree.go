package main

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

func traverse(root *TreeNode, codec *[]string) {
	if root == nil {
		*codec = append(*codec, "#")
		fmt.Println(codec)
		return
	}

	*codec = append(*codec, fmt.Sprintf("%v", root.Val))
	fmt.Println(codec)

	traverse(root.Left, codec)
	traverse(root.Right, codec)
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	codec := &[]string{}
	traverse(root, codec)
	fmt.Println(codec)
	return strings.Join(*codec, ",")
}

func buildTree(datas []string) *TreeNode {
	if len(datas) == 0 {
		return nil
	}
	strVal := datas[0]
	datas = datas[1:]
	if strVal == "#" {
		return nil
	}
	val, _ := strconv.ParseInt(strVal, 10, 64)

	root := &TreeNode{Val: int(val)}
	root.Left = buildTree(datas)
	root.Right = buildTree(datas)
	return root
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	datas := strings.Split(data, ",")
	return buildTree(datas)
}

func build(data *[]int) *TreeNode {
	if len(*data) == 0 {
		return nil
	}
	val := (*data)[0]
	*data = (*data)[1:]
	if val == -1 {
		return nil
	}
	root := &TreeNode{Val: val}
	root.Left = build(data)
	root.Right = build(data)
	return root
}

func b(a []int) {
	a = append(a, 2)
}
func main() {
	array := []int{1, 2, 3, -1, -1, 4, 5}
	root := build(&array)
	fmt.Println(root)
	ser := Constructor()
	deser := Constructor()
	data := ser.serialize(root)
	fmt.Println("data", data)
	ans := deser.deserialize(data)
	fmt.Println(ans)
}
