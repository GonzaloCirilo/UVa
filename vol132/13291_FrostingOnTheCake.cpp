#include <stdio.h>
int main() {
	int n;
	long long colors[3], ans[3], row, col;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < 3; i++) {
			colors[i] = 0;
			ans[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			scanf("%lld", &col);
			colors[i % 3] += col;
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &row);
			ans[(0 + i) % 3] += colors[0] * row;
			ans[(1 + i) % 3] += colors[1] * row;
			ans[(2 + i) % 3] += colors[2] * row;
		}
		
		printf("%lld %lld %lld\n", ans[1], ans[2], ans[0]);
	}
	return 0;
}