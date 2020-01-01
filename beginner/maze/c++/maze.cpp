#include <queue>

using namespace std;

int bfs();

const int INF = 100000000;
const int MAX_N = 10;
const int MAX_M = 10;

// state class
typedef pair<int, int> P;

// ===== ↓↓↓input↓↓↓ ===== //
int N = 10; // vertical
int M = 10; // horizontal
int sx = 0, sy = 1; // start position
int gx = 9, gy = 8; // goal position
char maze[10][10] = {
		{'#', 'S', '#', '#', '#', '#', '#', '#', '.' , '#'},
		{'.', '.', '.', '.', '.', '.', '#', '.', '.' , '#'},
		{'.', '#', '.', '#', '#', '.', '#', '#', '.' , '#'},
		{'.', '#', '.', '.', '.', '.', '.', '.', '.' , '.'},
		{'#', '#', '.', '#', '#', '.', '#', '#', '#' , '#'},
		{'.', '.', '.', '.', '#', '.', '.', '.', '.' , '#'},
		{'.', '#', '#', '#', '#', '#', '#', '#', '.' , '#'},
		{'.', '.', '.', '.', '#', '.', '.', '.', '.' , '.'},
		{'.', '#', '#', '#', '#', '.', '#', '#', '#' , '.'},
		{'.', '.', '.', '.', '#', '.', '.', '.', 'G' , '#'}
	};
// ===== ↑↑↑input↑↑↑ ===== //

// shortest distance of per point
int d[MAX_N][MAX_N];

// move 4 direction vector
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char *argv[]) {
	int res = bfs();
    printf("%d\n", res);
}

// get shortest distance from (sx, sy) to (gx, gy)
// INF if you can not reach
int bfs() { // Breadth-first search : bfs
    queue<P> que;
    // init INF for all point
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = INF;
        }
    }
    // set queue start position
    // this point distance zero
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // loop until the queue is empty
    while (que.size()) {
        // get queue of first
        P p = que.front();
        que.pop();
        printf("%d\n", que);
        
        // finish if state goal point
        if (p.first == gx && p.second == gy) break;
        
        // loop 4 derection   
        for (int i = 0; i < 4; i++) {
            // let (nx, ny) be the point after moving
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            // judge move avaivale and exist visited
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                // If you can move it, put it in the queue and determine the distance of that point as the distance from p + 1
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        } 
    }
    return d[gx][gy];
}
