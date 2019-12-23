package main

import (
	"fmt"
	"sort"
)

var n int

func main() {
	// ===== ↓↓↓input↓↓↓ ===== //
	n = 15
	var m float64
	m = 5
	k := []float64{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
	// ===== ↑↑↑input↑↑↑ ===== //

	sort.Float64s(k)

	var f bool
	f = false

	for a := 0; a < n; a++ {
		for b := 0; b < n; b++ {
			for c := 0; c < n; c++ {
				if binarySearch(m-k[a]-k[b]-k[c], k) {
					f = true
				}
			}
		}
	}

	if f {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func binarySearch(x float64, k []float64) bool {
	var l int
	l = 0
	var r int
	r = n

	for r-l >= 1 {
		var i = (l + r) / 2
		if k[i] == x {
			return true // found
		} else if k[i] < x {
			l = i + 1
		} else {
			r = i
		}
	}

	// not found
	return false
}
