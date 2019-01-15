#include <stdio.h>
int main() {
	int n, samples[10001];
	while (scanf("%d", &n) && n) {
		int ans = 0;
		for (int i = 0; i <= n + 1; i++) {
			if (i < n)
				scanf("%d", &samples[i]);
			if (i > 1) {
				int a = samples[(i - 2) % n], b = samples[(i - 1) % n], c = samples[i % n];
				if ((b < a && b < c) || (b > a && b > c))
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}