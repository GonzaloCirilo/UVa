#include <stdio.h>
#include <map>
int t, r, c, n, dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };
char grid[100][100], post[100][100], rune;
bool validCell(int nr, int nc) {
	return nr >= 0 && nr < r && nc >= 0 && nc < c;
}
int main() {
	std::map<char, char> dict;
	dict.insert({ 'S','P' });
	dict.insert({ 'P','R' });
	dict.insert({ 'R','S' });
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		scanf("%d %d %d\n", &r, &c, &n);
		for (int j = 0; j < r; j++) {
			int k = 0;
			while ((rune = getchar()) != '\n' && rune != EOF) {
				post[j][k] = 'N';
				grid[j][k++] = rune;
			}
		}
		while (n--) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					//
					for (int l = 0; l < 4; l++) {
						int nr = j + dr[l], nc = k + dc[l];
						if (validCell(nr, nc) && grid[nr][nc] == dict[grid[j][k]]) {
							post[nr][nc] = grid[j][k];
						}
					}
				}
			}
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					grid[j][k] = post[j][k] == 'N' ? grid[j][k] : post[j][k];
					post[j][k] = 'N';
				}
			}
		}
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				printf("%c", grid[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}