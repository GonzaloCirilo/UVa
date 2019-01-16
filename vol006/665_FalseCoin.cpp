#include <stdio.h>
int main() {
	int m, n, k, p, left[51], right[51], record[102];
	char op;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		if (i)
			printf("\n");
		scanf("%d %d", &n, &k);
		for (int j = 0; j <= n; j++)
			record[j] = 0;
		while (k--) {
			scanf("%d", &p);
			for (int j = 0; j < p; j++)
				scanf("%d", &left[j]);
			for (int j = 0; j < p; j++)
				scanf("%d", &right[j]);
			getchar();
			scanf("%c", &op);
			if (op == '=') {
				for (int j = 0; j < p; j++)	{
					record[left[j]] = 1;
					record[right[j]] = 1;
				}
			}
		}
		int ans = -1, cont = 0;
		for (int j = 1; j <= n; j++) {
			if (record[j] == 0) {
				cont++;
				ans = j;
			}
		}
		if (ans != -1 && cont == 1)
			printf("%d\n", ans);
		else
			printf("0\n");

	}

	return 0;
}