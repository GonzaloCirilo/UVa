#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int visited[22][22], n, m, x, y;
char grid[22][22], land;
ii moves[4] = { {-1,0},{1,0},{0,-1},{0,1} };
bool validPos(int r, int c) {
	return r >= 0 && r < m && c >= 0 && c < n;
}
int bfs(int r, int c) {
	int ans = 1;
	queue<ii> q;
	q.push({ r,c });
	visited[r][c] = 1;
	while (!q.empty()) {
		ii aux = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dr = (aux.first + moves[i].first), dc = ((aux.second + moves[i].second + n) % n);
			if (validPos(dr,dc) && !visited[dr][dc]) {
				visited[dr][dc] = true;
				q.push({ dr,dc });
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	while (scanf("%d %d\n", &m, &n) != EOF) {
		for (int i = 0; i < m; i++) {
			char token[22];
			fgets(token, 22, stdin);
			for (int j = 0; j < n; j++) {
				grid[i][j] = token[j];
			}
		}
		scanf("%d %d", &x, &y);
		land = grid[x][y];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = land != grid[i][j];
			}
		}
		bfs(x, y);
		int max = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					int aux = bfs(i, j);
					max = max < aux ? aux : max;
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}