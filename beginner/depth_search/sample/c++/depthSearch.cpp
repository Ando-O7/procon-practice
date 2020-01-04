#include <iostream>

bool dfs(int, int);
// ===== ↓↓↓input↓↓↓ ===== //
const int MAX_N = 4;
int n = MAX_N;
int a[MAX_N] = {1, 2, 4, 7};
int k = 13;
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	if (dfs(0, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// make a sum up to i and check the rest after i
bool dfs(int i, int sum) {
    // after determining n, return whether the sum so far is equal to k
	if (i == n) return sum == k;

    // not used a[i]
    if (dfs(i + 1, sum)) return true;

    // used a[i]
    if (dfs(i + 1, sum + a[i])) return true;

    // returns false because k cannot be created
    return false;
}
