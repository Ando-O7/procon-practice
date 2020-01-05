#include <algorithm>
using namespace std;

// ===== ↓↓↓input↓↓↓ ===== //
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6] = {3, 2, 1, 3, 0, 1};
int A = 620;
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	int ans = 0;

    for (int i = 5; i >= 0; i--) {
        int t = min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }

    printf("%d\n", ans);
}
