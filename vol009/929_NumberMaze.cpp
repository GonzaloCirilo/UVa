#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
priority_queue<iii, vector<iii>, greater<iii>>pq;
vector<vector<int>> distances;
vector<vector<int>> matrix;
int n, m;
vector<ii>moves = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
bool valid(int x, int y) {
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}
int main()
{
	int cases;
	scanf("%d", &cases);
	int matrix[1001][1001], distances[1001][1001];
	for (int c = 0; c < cases; c++) {
		scanf("%d\n%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &matrix[i][j]);
				distances[i][j] = -1;
			}
		}
		distances[0][0] = matrix[0][0];
		pq.push({ matrix[0][0],{ 0,0 } });
		while (!pq.empty()) {
			ii node = pq.top().second;
			int wnode = pq.top().first;
			pq.pop();
			if (distances[node.first][node.second] >= wnode) {
				for (int i = 0; i < moves.size(); i++) {
					ii ad = { node.first + moves[i].second,node.second + moves[i].first };
					if (valid(ad.second, ad.first)) {
						int newweight = wnode + matrix[ad.first][ad.second];
						if (distances[ad.first][ad.second] == -1 || distances[ad.first][ad.second] > newweight) {
							distances[ad.first][ad.second] = newweight;
							pq.push({ newweight,ad });
						}
					}
				}
			}
		}
		printf("%d\n", distances[n - 1][m - 1]);
	}
	return 0;
}
