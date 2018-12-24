#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;
typedef pair<int, int>ii;
int main() {
	int t, n, m, w, s;
	ii moves[2] = { {0,1},{1,0} };
	char tokens[101];
	vector<vector<int>> grid;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		scanf("%d %d\n", &n, &m);
		grid = vector<vector<int>>(n+1, vector<int>(m+1,0));
		for (int j = 0; j < n; j++) {
			fgets(tokens, 101, stdin);
			stringstream ss;
			ss = stringstream(string(tokens));
			ss >> w;
			while (ss >> s){
				grid[w][s] = -1;
			}
			
		}
		if (grid[1][1] == -1)
			printf("0\n");
		queue<ii> q;
		q.push({ 1,1 });
		grid[1][1] = 1;
		while (!q.empty() ) {
			ii aux = q.front(); q.pop();
			for (int j = 0; j < 2; j++) {
				int di = aux.first + moves[j].first, dj = aux.second + moves[j].second;
				if (di <= n && dj <= m && !grid[di][dj] && grid[di][dj] != -1) {
					if (grid[di - 1][dj] != -1)
						grid[di][dj] += grid[di - 1][dj];
					if (grid[di][dj - 1] != -1)
						grid[di][dj] += grid[di][dj - 1];
					q.push({ di,dj });
				}
			}
		}
		grid[n][m] = grid[n][m] == -1 ? 0 : grid[n][m];
		printf("%d\n", grid[n][m]);
	}
	return 0;
}