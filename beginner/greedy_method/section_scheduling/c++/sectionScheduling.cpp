#include <algorithm>
using namespace std;

// ===== ↓↓↓input↓↓↓ ===== //
const int MAX_N = 100000;
const int N = 5;
const int S[MAX_N] = {1, 2, 4, 6, 8}; 
const int T[MAX_N] = {3, 5, 7, 9, 10};
// ===== ↑↑↑input↑↑↑ ===== //

// Array for sort
pair<int, int> itv[MAX_N];

int main(int argc, char *argv[]) {
    // strage
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    // t is process end time
    int ans = 0, t = 0;
    for (int i = 0; i < N; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }

    printf("%d\n", ans);
}
