#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
char picture[55][55];
bool visited[55][55], visitedDots[55][55];
ii moves[5] = { {1,0},{0,1},{-1,0},{0,-1} };
int w,h;
bool validPos(ii pair) {
	return pair.first < h && pair.second < w && pair.first >= 0 && pair.second >= 0;
}
int bfs(int row, int col) {
	queue<ii> q;
	q.push({ row,col });
	visited[row][col] = true;
	int dots = 0;
	while (!q.empty()) {
		ii pos = q.front(); q.pop();
		if (picture[pos.first][pos.second] == 'X' && !visitedDots[pos.first][pos.second]) {
			//bfs for Dots Only
			queue<ii> qDots;
			qDots.push({ pos.first, pos.second });
			visitedDots[pos.first][pos.second] = true;
			while (!qDots.empty()) {
				ii dot = qDots.front(); qDots.pop();
				for (int i = 0; i < 5; i++) {
					ii newDot = { dot.first + moves[i].first,dot.second + moves[i].second };
					if (validPos(newDot) && !visitedDots[newDot.first][newDot.second]) {
						visitedDots[newDot.first][newDot.second] = true;
						qDots.push(newDot);
					}
				}
			}
			dots++;
		}
		for (int i = 0; i < 5; i++) {
			ii newPos = { pos.first + moves[i].first,pos.second + moves[i].second };
			if (validPos(newPos) && !visited[newPos.first][newPos.second]) {
				visited[newPos.first][newPos.second] = true;
				q.push(newPos);
			}
		}

	}
	return dots;
}
int main() {
	int counter = 1;
	while (scanf("%d %d\n", &w, &h) && w && h) {
		for (int i = 0; i < h; i++) {
			fgets(picture[i], w + 2, stdin);
			for (int j = 0; j < w; j++) {
				visited[i][j] = picture[i][j] == '.';
				visitedDots[i][j] = visited[i][j] || picture[i][j] == '*';
			}
		}
		printf("Throw %d\n", counter);
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j]) {
					//bfs
					pq.push(bfs(i, j));
				}
			}
		}
		printf("%d", pq.top()); pq.pop();
		while (!pq.empty()) {
			printf(" %d", pq.top()); pq.pop();
		}
		counter++;
		printf("\n\n");
	}
	return 0;
}