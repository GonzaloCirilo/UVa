#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int n, m; // size of grid rows & columns
char token, stringy[102];
bool visited[102][102];
ii moves[9] = { {1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{0,-1},{1,1},{-1,-1} };
bool validPocket(ii pocket) {
	return pocket.first < n && pocket.second < m && pocket.first >= 0 && pocket.second >= 0;
}
void bfs(int row, int col) {
	queue<ii> unvisitedPockets;
	unvisitedPockets.push({ row,col });
	while (!unvisitedPockets.empty()) {
		ii unPocket = unvisitedPockets.front(); unvisitedPockets.pop();
		visited[unPocket.first][unPocket.second] = true;
		for (int i = 0; i < 9; i++) {
			ii newPocket = { unPocket.first + moves[i].first, unPocket.second + moves[i].second };
			if (!visited[newPocket.first][newPocket.second] && validPocket(newPocket)) {
				unvisitedPockets.push(newPocket);
			}
		}
	}
}
int main() {
	int ans;
	queue<ii> pockets;
	while (scanf("%d %d", &n, &m) && n && m) {
		pockets = queue<ii>();
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", &stringy);
			for (int j = 0; j < m; j++) {
				if (stringy[j] == '@') {
					visited[i][j] = 0;
					pockets.push({ i,j });
				}
				else
					visited[i][j] = 1;				
			}
		}

		while (!pockets.empty()) {
			//do BFS if not visited
			ii pocket = pockets.front(); pockets.pop();
			if (!visited[pocket.first][pocket.second]) {
				bfs(pocket.first, pocket.second);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}