#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<vector<iii>>graph;
vector<int>distances;
vector<vector<int>>links;
int s, d;
void removePath(int t, vector<vector<int>>links) {
	if (t == s)
		return;
	for (int j = 0; j<links[t].size(); j++) {
		if (links[t][j] != -1) {
			for (int i = 0; i < graph[links[t][j]].size(); i++) {
				if (graph[links[t][j]][i].second.first == t) {
					graph[links[t][j]][i].second.second = 1;
				}
			}
		}
		removePath(links[t][j], links);
	}
}
void Dijkstra(int n, int s) {
	priority_queue<ii, vector<ii>, greater<ii>>pq;
	distances = vector<int>(n, -1);
	links = vector<vector<int>>(n);
	distances[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int node = pq.top().second;
		int wnode = pq.top().first;
		pq.pop();
		if (distances[node] >= wnode) {
			for (int j = 0; j < graph[node].size(); j++) {
				int allowPath = graph[node][j].second.second;
				int ad = graph[node][j].second.first;
				int wad = graph[node][j].first;
				int newweight = wnode + wad;
				if ((distances[ad] == -1 || distances[ad] >= newweight) && allowPath == 0) {
					if (distances[ad] > newweight) {
						links[ad].clear();
					}
					distances[ad] = newweight;
					pq.push({ newweight, ad });
					links[ad].push_back(node);
				}
			}
		}
	}
}
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && n && m) {
		scanf("%d %d", &s, &d);
		graph = vector<vector<iii>>(n);
		for (int i = 0; i < m; i++) {
			int u, v, t;
			scanf("%d %d %d", &u, &v, &t);
			graph[u].push_back({ t,{ v,0 } });
		}
		Dijkstra(n, s);
		removePath(d, links);
		Dijkstra(n, s);
		printf("%d\n", distances[d]);
	}
	return 0;
}
