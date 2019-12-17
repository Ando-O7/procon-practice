#include <iostream>
#include <algorithm>

using namespace std;
void slove();
const int MAX_N = 100;
int n, a[MAX_N];
int main(int argc, char *argv[]) {
	slove();
}
void slove() {
	int ans = 0;
	
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				int len = a[i] + a[j] + a[k];
				int max = std::max(a[i], std::max(a[j], a[k]));
				int rest = len - max;
				
				if (max < rest) {
					ans = std::max(ans, len);
				}
			}
		}
	}
	printf("%d¥n", ans);
}
