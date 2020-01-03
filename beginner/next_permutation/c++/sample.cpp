#include<algorithm>

const int MAX_N = 10;
const int MAX_M = 10;

bool used[MAX_N];
int perm[MAX_M];

void permutation1 (int pos, int n) {
    if (pos == n) {
        // Operations on perm[]
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int perm2[MAX_N];

void permutation2(int n) {
    for (int i = 0; i < n; i++) {
        perm2[i] = i;
    }
    do {
        // Operations on perm2[]
    } while (next_permutation(perm2, perm2 + n));
    return;
}
