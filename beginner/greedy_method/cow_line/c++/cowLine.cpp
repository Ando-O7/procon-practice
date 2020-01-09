#include <algorithm>

using namespace std;
// ===== ↓↓↓input↓↓↓ ===== //
const int MAX_N = 6;
int N = MAX_N;
char S[MAX_N] = {'A', 'C', 'D', 'B', 'C', 'B'};
// ===== ↑↑↑input↑↑↑ ===== //

int main(int argc, char *argv[]) {
	int a = 0, b = N - 1;
    
    while (a <= b) {
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (S[a + i] < S[b - i]) {
                left = true;
                break;
            }
            else if (S[a + i] > S[b - i]) {
                left = false;
                break;
            }
        }

        if (left) putchar(S[a++]);
        else putchar(S[b--]);
    }

    putchar('\n');
}
