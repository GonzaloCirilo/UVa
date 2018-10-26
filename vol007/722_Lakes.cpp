#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
char G[105][105];
bool visited[105][105];
ii moves[5] = { {1,0},{0,1},{-1,0},{0,-1} };
int i,j,w,h;
bool validWater(ii pair) {
	return pair.first < h && pair.second < w && pair.first >= 0 && pair.second >= 0;
}
int bfs(int row, int col) {
	queue<ii> q;
	q.push({ row,col });
	visited[row][col] = true;
	int waterCounter = 1;
	while (!q.empty()) {
		ii water = q.front(); q.pop();
		for (int k = 0; k < 5; k++) {
			ii newWater = { water.first + moves[k].first,water.second + moves[k].second };
			if (validWater(newWater) && !visited[newWater.first][newWater.second]) {
				visited[newWater.first][newWater.second] = true;
				q.push(newWater);
				waterCounter++;
			}
		}
	}
	return waterCounter;
}
int main() {
	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%2d %2d\n", &i, &j);
		h = 0; w = 0;
		while (fgets(G[h], 105, stdin) && G[h][0] != '\n') {
			w = strlen(G[h]) - 1 > w? strlen(G[h]) - 1: w;
			for (int l = 0; l < w; l++) {
				visited[h][l] = G[h][l] == '1';
			}
			h++;
		}
		if (m != 0)
			printf("\n");
		printf("%d\n", bfs(i-1,j-1));
	}
	
	return 0;
}