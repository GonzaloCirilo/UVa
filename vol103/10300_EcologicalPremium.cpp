#include <stdio.h>
int main() {
	int t, f, a, b, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &f);
		int ans = 0;
		while (f--) {
			scanf("%d %d %d", &a, &b, &c);
			ans += (a*c);
		}
		printf("%d\n", ans);
	}
}