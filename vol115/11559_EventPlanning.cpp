#include <stdio.h>
int main() {
	int n, b, h, w, p, a, ans;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
		ans = -1;
		for (int i = 0; i < h; i++) {
			scanf("%d", &p);
			int room = 0;
			for (int j = 0; j < w; j++) {
				scanf("%d", &a);
				if (a >= n)
					room = 1;
			}

			if ((ans == -1 || ans >= p * n) && p*n <= b && room) 
				ans = p * n;
		}
		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("stay home\n");
	}
	return 0;
}