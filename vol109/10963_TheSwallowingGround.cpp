#include <stdio.h>
#include <math.h>
int main() {
	int t, n, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");

		scanf("%d", &n);
		scanf("%d %d", &a, &b);
		n--;
		int aux = abs(a-b), ans = 1;
		while (n--) {
			scanf("%d %d", &a, &b);
			if (aux != abs(a - b))
				ans = 0;
		}
		if (ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}