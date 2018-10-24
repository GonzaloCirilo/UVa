#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int>ii;
int n, visited[26][26];
ii moves[9] = { {1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{0,-1},{1,1},{-1,-1} };
bool validEagle(ii eagle) {
	return eagle.first >= 0 && eagle.first < n && eagle.second >= 0 && eagle.second < n;
}
void bfs(int row, int col) {
	queue<ii> eagles;
	eagles.push({ row,col });
	visited[row][col] = true;
	while (!eagles.empty()) {
		ii eagle = eagles.front(); eagles.pop();
		for (int i = 0; i < 9; i++) {
			ii newEagle = { eagle.first + moves[i].first,eagle.second + moves[i].second };
			if (validEagle(newEagle) && !visited[newEagle.first][newEagle.second]) {
				eagles.push(newEagle);
				visited[newEagle.first][newEagle.second] = true;
			}
		}
	}
}
int main() {//352
	char token[26]; int t = 1;
	queue<ii> ones;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s", &token);
			for (int j = 0; j < n; j++) {
				visited[i][j] = token[j] == '0';
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					//bfs
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", t, ans);
		t++;
	}
	return 0;
}