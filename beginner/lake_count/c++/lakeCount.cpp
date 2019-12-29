#include <iostream>

void dfs(int, int);
void slove();
// ===== ↓↓↓input↓↓↓ ===== //
int N = 10;
int M = 12;
char field[10][12] = {
		{'W', '.', '.', '.', '.', '.', '.', '.', '.' , 'W', 'W', '.'},
		{'.', 'W', 'W', 'W', '.', '.', '.', '.', '.' , 'W', 'W', 'W'},
		{'.', '.', '.', '.', 'W', 'W', '.', '.', '.' , 'W', 'W', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.' , 'W', 'W', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.' , 'W', '.', '.'},
		{'.', '.', 'W', '.', '.', '.', '.', '.', '.' , 'W', '.', '.'},
		{'.', 'W', '.', 'W', '.', '.', '.', '.', '.' , 'W', 'W', '.'},
		{'W', '.', 'W', '.', 'W', '.', '.', '.', '.' , '.', 'W', '.'},
		{'.', 'W', '.', 'W', '.', '.', '.', '.', '.' , '.', 'W', '.'},
		{'.', '.', 'W', '.', '.', '.', '.', '.', '.' , '.', 'W', '.'}
	};

// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	slove();
}

// current position x,y
void dfs(int x, int y) {
	// replace
	field[x][y] = '.';

	// roop for move 8 directions
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy < 1; dy++) {
			int nx = x + dx, ny = y + dy;

			// judge for in field & lake
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
		}
	}

}

void slove() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'W') {
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}
