#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
char grid[105][105];
bool visited[105][105];
ii moves[5] = { {1,0},{0,1},{-1,0},{0,-1} };
int t, n;
bool validPoint(ii pair) {
	return pair.first < n && pair.second < n && pair.first >= 0 && pair.second >= 0;
}
int bfs(int row, int col) {
	queue<ii> q;
	int isNotDeadShip = grid[row][col] == 'x';
	q.push({ row, col });
	visited[row][col] = true;
	while (!q.empty()) {
		ii point = q.front(); q.pop();
		for (int i = 0; i < 5; i++) {//expansion in this problem should be diff but it seems too work the normal way
			ii newPoint = { point.first + moves[i].first,point.second + moves[i].second };
			if (validPoint(newPoint) && !visited[newPoint.first][newPoint.second]) {
				visited[newPoint.first][newPoint.second] = true;
				q.push(newPoint);
				isNotDeadShip = (isNotDeadShip || grid[newPoint.first][newPoint.second]=='x');
			}
		}
	}
	return isNotDeadShip;
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d\n", &n);
		for (int j = 0; j < n; j++) {
			fgets(grid[j], 105, stdin);
			for (int k = 0; k < n; k++) {
				visited[j][k] = grid[j][k] == '.';
			}
		}
		int ans = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k]) {
					ans += bfs(j, k);
				}
			}
		}
		printf("Case %d: %d\n", i + 1, ans);
	}
	return 0;
}