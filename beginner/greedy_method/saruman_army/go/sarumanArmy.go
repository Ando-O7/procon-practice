package main

import (
	"fmt"
	"sort"
)

// ===== ↓↓↓input↓↓↓ ===== //

var N int = 6
var R int = 10
var X = []int{1, 7, 15, 20, 30, 50}

// ===== ↑↑↑input↑↑↑ ===== //

func main() {
	sort.Ints(X)

	i := 0
	ans := 0
	for i < N {
		i++
		s := X[i]

		for i < N && X[i] <= s+R {
			i++
		}

		p := X[i-1]

		for i < N && X[i] <= p+R {
			i++
		}

		ans++
	}
	fmt.Print(ans)
}
