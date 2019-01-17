#include <stdio.h>
#include <math.h>
int main() {
	int n, di, prev;
	while (scanf("%d", &n) != EOF) {
		int taken[10001] = {};
		scanf("%d", &prev);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &di);
			taken[abs(di - prev)] = 1;
			prev = di;
		}
		bool ans = true;
		for (int i = 1; i < n; i++) {
			ans = ans && taken[i];
		}
		if (ans)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}