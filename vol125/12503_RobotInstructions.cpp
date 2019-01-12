#include <stdio.h>
int main() {
	int t, n, order[101], pos;
	char token[20];
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++) {
			fgets(token, 20, stdin);
			if (token[0] == 'L') {
				ans--;
				order[i] = -1;
			}
			else if (token[0] == 'R') {
				ans++;
				order[i] = 1;
			}
			else {
				sscanf(token, "SAME AS %d", &pos);
				ans += order[pos - 1];
				order[i] = order[pos - 1];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}