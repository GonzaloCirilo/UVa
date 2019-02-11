#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	int n;
	char cards[53][2], token[21];
	while (scanf("%d", &n) && n) {
		char order[53][2] = {};
		int start = -1;
		for (int i = 0; i < n; i++) {
			scanf("%s %s", &cards[i], &token);
			int l = strlen(token);
			while (l) {
				start++;
				start %= n;
				if (order[start][0] == '\0')
					l--;
			}
			order[start][0] = cards[i][0], order[start][1] = cards[i][1];
		}
		for (int i = 0; i < n; i++) {
			if (i)printf(" ");
			printf("%c%c", order[i][0], order[i][1]);
		}
		printf("\n");
	}
	return 0;
}