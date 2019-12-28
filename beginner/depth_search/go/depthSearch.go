package main

import "fmt"

// ===== ↓↓↓input↓↓↓ ===== //
var n int = 4
var a = []int{1, 2, 4, 7}
var k int = 13

// ===== ↑↑↑input↑↑↑ ===== //

func main() {
	if dfs(0, 0) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func dfs(i int, sum int) bool {
	if i == n {
		return sum == k
	}

	if dfs(i+1, sum) {
		return true
	}

	if dfs(i+1, sum+a[i]) {
		return true
	}

	return false
}
