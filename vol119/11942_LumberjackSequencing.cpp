#include <stdio.h>
int main() {
	int n, beards[10];
	printf("Lumberjacks:\n");
	scanf("%d", &n);
	while (n--) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &beards[j]);
		}
		int desc = true, asc = true;
		for (int j = 0; j < 9; j++) {
			if (beards[j] < beards[j + 1])
				desc = false;
		}
		for (int j = 0; j < 9; j++) {
			if (beards[j] > beards[j + 1])
				asc = false;
		}
		if (asc || desc)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}