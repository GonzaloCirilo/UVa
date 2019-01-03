#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
ii moves[4] = { {1,0},{-1,0},{0,1},{0,-1} };
bool validCell(int _r, int _c) {
	return _r >= 0 && _r < 2000 && _c >= 0 && _c < 2000;
}
int main() {
	int m1, m2, x, y;
	vector<vector<int>>grid;
	while (scanf("%d", &m1) && m1) {
		grid = vector<vector<int>>(2003, vector<int>(2003,0));
		list<iii>q;
		for (int i = 0; i < m1; i++) {
			scanf("%d %d", &x, &y);
			grid[x][y] = 1;
			q.push_back({ 0,{ x,y } });
		}
		scanf("%d", &m2);
		for (int i = 0; i < m2; i++) {
			scanf("%d %d", &x, &y);
			grid[x][y] = 2;
		}
		bool finished = false;
		int ans = 0;
		while (!q.empty() && !finished) {
			auto node = q.front(); q.pop_front();
			for (int i = 0; i < 4; i++) {
				int dr = node.second.first + moves[i].first, dc = node.second.second + moves[i].second;
				if (validCell(dr, dc) && grid[dr][dc] == 2) {
					finished = true;
					ans = node.first + 1;
				}
				if (validCell(dr, dc) && !grid[dr][dc]) {
					grid[dr][dc] = 3;
					q.push_back({ node.first + 1,{dr,dc} });
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}