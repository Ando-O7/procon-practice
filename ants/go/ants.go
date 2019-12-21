package main

import (
	"fmt"
	"math"
)

func main() {
	// ===== ↓↓↓input↓↓↓ ===== //
	var L float64
	L = 10
	var n = 3
	x := []float64{2, 6, 7}
	// ===== ↑↑↑input↑↑↑ ===== //

	// min time
	var min float64
	min = 0
	for i := 0; i < n; i++ {
		min = math.Max(min, math.Min(x[i], L-x[i]))
	}

	// max time
	var max float64
	max = 0
	for i := 0; i < n; i++ {
		max = math.Max(max, math.Max(x[i], L-x[i]))
	}

	fmt.Println(min)
	fmt.Println(max)
}
