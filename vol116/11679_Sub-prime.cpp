#include <stdio.h>
int main() {
	int n, b, reserves[22], u, v, w;
	while (scanf("%d %d", &b, &n) && b && n) {
		for (int i = 0; i < b; i++) {
			scanf("%d", &reserves[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			reserves[u] -= w;
			reserves[v] += w;
		}
		bool ans = true;
		for (int i = 0; i < b; i++) {
			if (reserves[i] < 0)
				ans = false;
		}
		if (ans)
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}