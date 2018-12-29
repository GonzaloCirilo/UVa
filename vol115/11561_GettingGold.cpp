#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int visited[53][53], w, h, x, y;
char grid[53][53], land;
ii moves[4] = { {-1,0},{1,0},{0,-1},{0,1} };
bool validPos(int r, int c) {
	return r >= 0 && r < h && c >= 0 && c < w;
}
int bfs(int r, int c) {
	int ans = 0;
	queue<ii> q;
	q.push({ r,c });
	visited[r][c] = 1;
	while (!q.empty()) {
		ii aux = q.front(); q.pop();
		bool danger = false;
		for (int i = 0; i < 4; i++) {
			int dr = aux.first + moves[i].first, dc = aux.second + moves[i].second;
			if (validPos(dr, dc) && grid[dr][dc] == 'T') {
				danger = true;
			}
		}
		if (danger)continue;
		for (int i = 0; i < 4; i++) {
			int dr = aux.first + moves[i].first, dc = aux.second + moves[i].second;
			if (validPos(dr,dc) && !visited[dr][dc]) {
				visited[dr][dc] = true;
				q.push({ dr,dc });
				if(grid[dr][dc] == 'G')
					ans++;
			}
		}
	}
	return ans;
}
int main() {
	int sr, sc;
	while (scanf("%d %d\n", &w, &h) != EOF) {
		for (int i = 0; i < h; i++) {
			char token[53];
			fgets(token, 53, stdin);
			for (int j = 0; j < w; j++) {
				grid[i][j] = token[j];
				visited[i][j] = token[j] != '.' && token [j] != 'G';
				if (token[j] == 'P')
					sr = i, sc = j;
			}
		}
		printf("%d\n", bfs(sr, sc));
	}
	return 0;
}