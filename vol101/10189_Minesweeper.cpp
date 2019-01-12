#include <stdio.h>
int n, m, dr[3] = { -1,0,1 }, dc[3] = { -1,0,1 }, cont = 1;
bool validPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
int main() {
	
	while (scanf("%d %d\n", &n, &m) && n && m) {
		if (cont != 1)
			printf("\n");
		int grid[101][101] = {};
		char token[101][101] = {};
		for (int i = 0; i < n; i++) {
			//fgets(token[i], 101, stdin);
			scanf("%s\n", token[i]);
			for (int j = 0; j < m; j++) {
				if (token[i][j] == '*')
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							int di = i + dr[k], dj = j + dc[l];
							if (validPos(di, dj)) {
								if (token[di][dj] == '*')
									grid[di][dj] = -1;
								else
									grid[di][dj]++;
							}
						}
					}
			}
		}
		printf("Field #%d:\n", cont);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == -1)
					printf("*");
				else
					printf("%d", grid[i][j]);
			}
			printf("\n");
		}
		cont++;
	}
	return 0;
}