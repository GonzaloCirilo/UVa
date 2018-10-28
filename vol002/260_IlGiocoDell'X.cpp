#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
char board[205][205];
bool visited[205][205];
bool cols[205];
ii moves[7] = { {-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1} };
int n;
char validWater(ii pair) {
	return pair.first < n && pair.second < n && pair.first >= 0 && pair.second >= 0;
}
bool bfs(int row, int col) {
	queue<ii> q;
	q.push({ row,col });
	visited[row][col] = true;
	while (!q.empty()) {
		ii water = q.front(); q.pop();
		for (int k = 0; k < 7; k++) {
			ii newWater = { water.first + moves[k].first,water.second + moves[k].second };
			if (validWater(newWater) && !visited[newWater.first][newWater.second]) {
				visited[newWater.first][newWater.second] = true;
				cols[newWater.second] = true;
				q.push(newWater);
			}
		}
	}
	return cols[n-1];
}
int main() {
	int counter = 1;
	while (scanf("%d\n", &n) != EOF && n) {
		for (int i = 0; i < n; i++) {
			fgets(board[i], 205, stdin);
			cols[i] = false;
			for (int j = 0; j < n; j++) {
				visited[i][j] = board[i][j] == 'b';
			}
		}
		char ans = 'B';
		for (int i = 0; i < n; i++) {
			//bfs
			if (!visited[i][0] && bfs(i, 0)) {
				ans = 'W';
				break;
			}

		}
		printf("%d %c\n", counter, ans);
		counter++;
	}
	
	return 0;
}