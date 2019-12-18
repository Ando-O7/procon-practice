package main

import (
	"fmt"
	"math"
)

func main() {
	// ===== ↓↓↓input↓↓↓ ===== //
	var n = 5
	a := []float64{2, 3, 4, 5, 10}
	// ===== ↑↑↑input↑↑↑ ===== //

	var ans float64
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				var len = a[i] + a[j] + a[k]
				var max = math.Max(a[i], math.Max(a[j], a[k]))
				var rest = len - max

				if max < rest {
					ans = math.Max(ans, len)
				}
			}
		}
	}
	fmt.Println(ans)
}
