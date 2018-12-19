#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
ii moves[4] = { {-1,0},{1,0},{0,-1},{0,1} };
int t, n, m, y, grid[1002][1002], pset[1000002];
bool validCell(ii pos) {
	return pos.first < n && pos.first >= 0 && pos.second < m && pos.second >= 0;
}
int findset(int n) {
	if (pset[n] == -1)
		return n;
	return pset[n] = findset(pset[n]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
int unionSet(int a, int b){
	if (!isSameSet(a, b)) {
		pset[findset(a)] = findset(b);
		return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &t);
	int ys[100001];
	stack<int> ss;
	while (t) {
		vector<iii> v;
		scanf("%d %d", &n, &m);
		int cont = 0, nodes = n * m, ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &grid[i][j]);
				v.push_back({ grid[i][j],{i,j} });
				pset[cont++] = -1;
			}
		}
		sort(v.rbegin(), v.rend());
		scanf("%d", &y);
		for (int i = 0; i < y; i++)
			scanf("%d", &ys[i]);
		cont = 0;
		for (int i = y - 1; i >= 0; i--) {
			while (cont < nodes && v[cont].first > ys[i]) {
				iii a = v[cont];
				for (int j = 0; j < 4; j++) {
					int di = a.second.first + moves[j].first, dj = a.second.second + moves[j].second;
					if (validCell({ di,dj }) && grid[di][dj] > ys[i]) {
						ans -= unionSet(a.second.second * n + a.second.first, dj * n + di);
					}
				}
				ans++, cont++;
			}
			ss.push(ans);
		}
		while (!ss.empty()) {
			printf("%d ", ss.top());
			ss.pop();
		}
		printf("\n");
		t--;
	}
	return 0;
}