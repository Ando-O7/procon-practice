package main

import "fmt"

// ===== ↓↓↓input↓↓↓ ===== //
var N int = 10
var M int = 12
var field [][]string

// ===== ↑↑↑input↑↑↑ ===== //

func main() {
	var res int = 0
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			if field[i][j] == "W" {
				dfs(i, j)
				res++
			}
		}
	}
	fmt.Println("%d\n", res)
}

func dfs(x int, y int) {
	field[x][y] = "."

	for dx := -1; dx <= 1; dx++ {
		for dy := -1; dy <= 1; dy++ {
			var nx int = x + dx
			var ny int = y + dy

			if (0 <= nx) && (nx < N) && 0 <= ny && ny < M && field[nx][ny] == "W" {
				dfs(nx, ny)
			}
		}
	}
}
