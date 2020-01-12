#include <algorithm>

using namespace std;
// ===== ↓↓↓input↓↓↓ ===== //
int N = 6;
int R = 10;
int X[6] = {1, 7, 15, 20, 30, 50}; 
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	sort(X, X + N);

    int i = 0, ans = 0;
    while (i < N) {
        // s is not cover leftest point
        int s = X[i++];

        while (i < N && X[i] <= s + R) i++;

        // p is next point
        int p = X[i - 1];
        
        // move until p is beyond R
        while (i <  N && X[i] <= p + R) i++;

        ans++;
    }
    printf("%d\n", ans);
}
