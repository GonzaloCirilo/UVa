#include <stdio.h>

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		char line[4] = {};
		int x[8] = {}, o[8] = {};
		for (int i = 0; i < 3; i++) {
			scanf("%s", &line);
			for (int j = 0; j < 3; j++) {
				char c = line[j];
				x[i] += (c == 'X');
				x[j + 3] += (c == 'X');
				o[i] += (c == 'O');
				o[j + 3] += (c == 'O');
				if (i == j) {
					x[6] += (c == 'X');
					o[6] += (c == 'O');
				}
				if (i + j == 2) {
					x[7] += (c == 'X');
					o[7] += (c == 'O');
				}

			}
		}
		int countX = 0, countO = 0;
		for (int i = 0; i < 8; i++) {
			if (x[i] == 3) countX++;
			if (o[i] == 3) countO++;
		}
		fgets(line, 10, stdin);
		int xs = x[0] + x[1] + x[2], os = o[0] + o[1] + o[2];
		//printf("%d %d\n", xs, os);
		if (((xs - os == 0 && countX == 0 )|| (xs - os == 1 && countO == 0)))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}