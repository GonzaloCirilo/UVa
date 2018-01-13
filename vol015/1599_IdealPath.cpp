#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii>iii;
vector<int>found, acw;
vector<vector<ii>>graph;
int n, m, a, b, c;
int INF = 999999;
void BFS_Rev(int s, int t) {
	queue<pair<int, int>>q;
	q.push({ s,0 });
	found[s] = 0;
	acw[s] = 0;
	while (!q.empty()) {
		int r = q.front().first, w = q.front().second;
		q.pop();
		for (int i = 0; i<graph[r].size(); i++) {
			int d = graph[r][i].second;
			if(acw[d]>acw[r] + graph[r][i].first)
				acw[d] = acw[r] + graph[r][i].first;
			if (found[d] == INF) {
				found[d] = w + 1;
				//if (d == t)return;
				q.push({ d,w + 1 });
			}
		}
	}
}
void BFS(int s, int t) {
	priority_queue<ii,vector<ii>,greater<ii>>ad, aux; vector<int> visited = vector<int>(t + 1, 0);
	priority_queue<iii, vector<iii>, greater<iii>>pqmin;
	visited[0] = 1;
	ad.push({ 0,s });
	for (int i = 0; i < found[s]; i++) {
		pqmin = priority_queue<iii, vector<iii>, greater<iii>>();
		aux = priority_queue<ii, vector<ii>, greater<ii>>();
		if (i != 0)printf(" ");
		while (!ad.empty()) {
			int c = ad.top().first; int r = ad.top().second; ad.pop();
			for (int k = 0; k < graph[r].size(); k++) {
				int d = graph[r][k].second;
				if (found[r] - 1 == found[d]) {
					pqmin.push({ graph[r][k].first,{acw[r],r} });
				}
			}
		}
		int r = pqmin.top().second.second;
		printf("%d", pqmin.top().first);
		for (int k = 0; k < graph[r].size(); k++) {
			int d = graph[r][k].second;
			if (found[r] - 1 == found[d] && graph[r][k].first == pqmin.top().first && !visited[d]) {
				visited[d] = 1;
				aux.push({ pqmin.top().first,d });
			}
		}
		ad = aux;
	}
}
int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		graph = vector<vector<ii>>(n);
		found = vector<int>(n, INF);
		acw = vector<int>(n, INF);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			a--, b--;
			graph[a].push_back({ c,b });
			graph[b].push_back({ c,a });
		}
		int s = 0, t = n - 1;
		BFS_Rev(t, s);
		printf("%d\n", found[s]);
		BFS(s, t);
		printf("\n");
	}
	return 0;
}
/*
6 6
1 2 1
1 3 1
2 4 1
3 5 1
4 6 2
5 6 1
4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1
4 4
1 2 1
1 3 1
2 4 4
3 4 3
20 26
7 16 1
16 12 1
17 9 6
2 16 1
14 16 1
1 11 1
18 16 1
1 14 1
1 15 1
1 18 1
5 3 4
1 10 1
9 6 2
15 16 1
4 16 1
8 20 2
19 8 8
10 16 1
6 19 3
12 5 7
1 4 1
13 17 6
1 2 1
1 7 1
11 16 1
3 13 8
5 6
1 3 2
3 4 1
3 5 2
4 5 3
1 2 4
2 5 1
5 6
1 3 2
1 4 2
5 4 2
3 5 3
1 2 4
2 5 1
2 2
1 1 1
1 2 5
*/
