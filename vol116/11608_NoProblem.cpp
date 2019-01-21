#include <stdio.h>
int main() {
	int s, cases = 1, problems[12], req[12];
	while (scanf("%d", &s) && s >= 0) {
		printf("Case %d:\n", cases++);
		for (int i = 0; i < 12; i++)
			scanf("%d", &problems[i]);
		for (int i = 0; i < 12; i++)
			scanf("%d", &req[i]);
		for (int i = 0; i < 12; i++) {
			if (req[i] <= s) {
				printf("No problem! :D\n");
				s -= req[i];
			}
			else
				printf("No problem. :(\n");
			s += problems[i];
		}
	}
	return 0;
}