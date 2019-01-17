#include <stdio.h>
int main() {
	int t, n, p, h[100];
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n%d", &n, &p);
		for (int i = 0; i < p; i++)
			scanf("%d", &h[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if ((i-6) % 7 == 0 || i % 7 == 0)continue;
			for (int j = 0; j < p; j++) {
				if (i % h[j] == 0) {
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}