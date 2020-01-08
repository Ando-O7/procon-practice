package main

import (
	"fmt"
	"sort"
)

// ===== ↓↓↓input↓↓↓ ===== //
const (
	MAX_N int = 100000
	N     int = 5
)

var S = []int{1, 2, 4, 6, 8}
var T = []int{3, 5, 7, 9, 10}

// ===== ↑↑↑input↑↑↑ ===== //

type Pair struct {
	x, y int
}

func main() {
	itv := make([]Pair, N)
	sort.Ints(T)
	sort.Ints(S)

	for i := 0; i < N; i++ {
		itv[i].x = T[i]
		itv[i].y = S[i]
	}

	ans := 0
	t := 0
	for i := 0; i < N; i++ {
		if t < itv[i].y {
			ans++
			t = itv[i].x
		}
	}

	fmt.Println(ans)
}
