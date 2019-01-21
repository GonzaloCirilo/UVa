#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
	int n, k, r;
	while (scanf("%d %d", &n, &k) != EOF) {
		int ans = 0; r = 0;
		while (n != 0 || r >= k) {
			ans += n;
			r += n;
			n = r / k;
			r -= n * k;
		}
		printf("%d\n", ans);
	}
	return 0;
}