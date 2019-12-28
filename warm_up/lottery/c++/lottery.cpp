#include <iostream>
#include <algorithm>

using namespace std;
void slove();
bool binarySearch(int x);
// ===== ↓↓↓input↓↓↓ ===== //
const int MAX_N = 15;
int n = MAX_N;
int m = 5;
int k[MAX_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	slove();
}
void slove() {
	// sort for binary search
    std::sort(k, k + n);

    bool f = false;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                // binary search instead of loop
                printf("%d\n", (m - k[a] - k[b] - k[c]));
                if (binarySearch(m - k[a] - k[b] - k[c])) {
                    f = true;
                }
            }
        }
    }

    if (f) puts("Yes");
    else puts("No");
}

bool binarySearch(int x) {
    // x range is k[l], k[l+1], ..., k[r-1]...
    int l = 0, r = n;

    while (r - l >= 1) {
        int i = (l + r) / 2;
        if (k[i] == x) return true; // found
        else if (k[i] < x) l = i + 1;
        else r = i;
    }

    // not found
    return false;
}