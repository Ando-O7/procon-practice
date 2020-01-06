package main

import (
	"fmt"
	"math"
)

func main() {
	// ===== ↓↓↓input↓↓↓ ===== //
	V := [6]int{1, 5, 10, 50, 100, 500}
	C := [6]int{3, 2, 1, 3, 0, 1}
	A := 620
	// ===== ↑↑↑input↑↑↑ ===== //

	ans := 0

	for i := 5; i >= 0; i-- {
		t := int(math.Min(float64(A/V[i]), float64(C[i])))
		A -= t * V[i]
		ans += t
	}

	fmt.Println(ans)
}
