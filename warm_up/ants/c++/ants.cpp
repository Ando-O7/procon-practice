#include <iostream>
#include <algorithm>

using namespace std;
void slove();
// ===== ↓↓↓input↓↓↓ ===== //
const int MAX_N = 3;
int L = 10;
int n = MAX_N;
int x[MAX_N] = {2, 6, 7};
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	slove();
}
void slove() {
	// min time
	int min_time = 0;
	for (int i = 0; i < n; i++) {
		min_time = std::max(min_time, std::min(x[i], L - x[i]));
	}
	// max time
	int max_time = 0;
	for (int i = 0; i < n; i++) {
		max_time = std::max(max_time, std::max(x[i], L - x[i]));
	}
	
	printf("%d %d\n", min_time, max_time);
}
