#include <stdio.h>
#include <queue>
#include <sstream>
using namespace std;
typedef pair<int, int> ii;
bool visited[110][110];
int o, m;
int areas[110][110];
ii moves[9] = { {1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{0,-1},{1,1},{-1,-1} };
bool validWater(ii pair) {
	return pair.first < o && pair.second < m && pair.first >= 0 && pair.second >= 0;
}
int dfs(int row, int col) {
	int waterCounter = 1;
	queue<ii> discovered;
	if (areas[row][col] != 0)
		return areas[row][col];
	else {
		//do bfs
		queue<ii> unvisitedWater;
		unvisitedWater.push({ row,col });
		discovered.push({ row,col });
		visited[row][col] = true;
		while (!unvisitedWater.empty()) {
			ii unWater = unvisitedWater.front(); unvisitedWater.pop();
			for (int i = 0; i < 9; i++) {
				ii newWater = { unWater.first + moves[i].first, unWater.second + moves[i].second };
				if (validWater(newWater) && !visited[newWater.first][newWater.second] ) {
					unvisitedWater.push(newWater);
					discovered.push(newWater);
					visited[newWater.first][newWater.second] = true;
					waterCounter++;
				}
			}
		}
	}
	// iterate over discovered nodes and cache the answer
	while (!discovered.empty()) {
		ii ob = discovered.front(); discovered.pop();
		areas[ob.first][ob.second] = waterCounter;
	}
	return waterCounter;
}
int main() {
	int t, r, c;
	char stringy[110];
	scanf("%d\n\n", &t);
	for (int i = 0; i < t; i++) {
		int j = 0;
		if (i > 0) {
			printf("\n");
		}
		while (fgets(stringy,110,stdin) && stringy[0] != '\n') {
			if (stringy[0] == 'L' || stringy[0] == 'W') {
				int k = 0;
				while (stringy[k] != '\n') {
					visited[j][k] = stringy[k] == 'L';
					areas[j][k] = 0;
					k++;
				}
				m = k;
				j++;
			}
			else {
				o = j;
				sscanf(stringy, "%d %d", &r, &c);
				printf("%d\n", dfs(r - 1, c - 1));
			}
		}
		
	}
	return 0;
}