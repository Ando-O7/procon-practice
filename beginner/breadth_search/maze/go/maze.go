package main

import (
	"fmt"
)

const INF = 100000000
const MAX_N int = 10
const MAX_M int = 10

type Pair struct {
	x, y int
}

var d = [MAX_N][MAX_M]int{}

var dx = [4]int{1, 0, -1, 0}
var dy = [4]int{0, 1, 0, -1}

// ===== ↓↓↓input↓↓↓ ===== //
var N, M, sx, sy, gx, gy int = 10, 10, 0, 1, 9, 8
var maze = [10][10]string{
	{"#", "S", "#", "#", "#", "#", "#", "#", ".", "#"},
	{".", ".", ".", ".", ".", ".", "#", ".", ".", "#"},
	{".", "#", ".", "#", "#", ".", "#", "#", ".", "#"},
	{".", "#", ".", ".", ".", ".", ".", ".", ".", "."},
	{"#", "#", ".", "#", "#", ".", "#", "#", "#", "#"},
	{".", ".", ".", ".", "#", ".", ".", ".", ".", "#"},
	{".", "#", "#", "#", "#", "#", "#", "#", ".", "#"},
	{".", ".", ".", ".", "#", ".", ".", ".", ".", "."},
	{".", "#", "#", "#", "#", ".", "#", "#", "#", "."},
	{".", ".", ".", ".", "#", ".", ".", ".", "G", "#"},
}

// ===== ↑↑↑input↑↑↑ ===== //

func main() {
	res := bfs()
	fmt.Println(res)
}

func bfs() int {
	que := make([]Pair, 0)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			d[i][j] = INF
		}
	}

	que = append(que, Pair{sx, sy})
	d[sx][sy] = 0

	for len(que) > 0 {
		p := que[0]
		que = que[1:]
		if p.x == gx && p.y == gy {
			break
		}

		for i := 0; i < 4; i++ {
			nx := p.x + dx[i]
			ny := p.y + dy[i]

			if 0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != "#" && d[nx][ny] == INF {
				que = append(que, Pair{nx, ny})
				d[nx][ny] = d[p.x][p.y] + 1
			}
		}
	}
	return d[gx][gy]
}
