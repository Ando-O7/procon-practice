package main

import "fmt"

// ===== ↓↓↓input↓↓↓ ===== //
const MAX_N = 6
const N = MAX_N

var S = [MAX_N]string{"A", "C", "D", "B", "C", "B"}

// ===== ↑↑↑input↑↑↑ ===== //

func main() {
	a := 0
	b := N - 1

	for a <= b {
		left := false
		for i := 0; a+i <= b; i++ {
			if S[a+i] < S[b-i] {
				left = true
				break
			} else if S[a+i] > S[b-i] {
				left = false
				break
			}
		}

		if left {
			fmt.Print(S[a])
			a++
		} else {
			fmt.Print(S[b])
			b--
		}
	}
}
