#include <stdio.h>
int main() {
	int t, n, c, ans, cont = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &c);
			if (c > ans)
				ans = c;
		}
		printf("Case %d: %d\n", cont++, ans);
	}
	return 0;
}