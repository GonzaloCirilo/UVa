#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <sstream>
using namespace std;
typedef pair<int, int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
typedef vector<vii>G;
priority_queue<ii, vector<ii>, greater<ii>>pq;
int Dijkstra(vi distances, G graph, int inter) {
	graph[0].push_back({ 0,inter });
	while (!pq.empty()) {
		int node = pq.top().second;
		int wnode = pq.top().first;
		pq.pop();
		if (distances[node] >= wnode) {
			for (int j = 0; j < graph[node].size(); j++) {
				int ad = graph[node][j].second;
				int wad = graph[node][j].first;
				int neweight = wnode + wad;
				if (neweight < distances[ad]) {
					distances[ad] = neweight;
					pq.push({ neweight,ad });
				}
			}
		}
	}
	return *max_element(distances.begin(), distances.end());
}
int main() {
	string l;
	int t, f, i, fi, u, v, w, inf = 9999999;
	scanf("%d", &t);
	cin.ignore();
	vi distances;
	G graph;
	for (int tc = 0; tc < t; tc++) {
		if (tc != 0)printf("\n");
		scanf("%d %d", &f, &i);
		graph = G(i + 1);
		for (int j = 0; j < f; j++) {
			scanf("%d", &fi);
			graph[0].push_back({ 0,fi });
		}
		cin.ignore();
		while (getline(cin, l) && l != "") {
			sscanf(l.c_str(), "%d %d %d", &u, &v, &w);
			graph[u].push_back({ w,v });
			graph[v].push_back({ w,u });
		}
		int mini = inf, index;
		distances = vi(i + 1, inf);
		for (int j = 0; j < i; j++) {
			pq.push({ distances[0] = 0,0 });
			int aux = Dijkstra(distances, graph, j + 1);
			if (mini > aux) {
				mini = aux;
				index = j + 1;
			}
		}
		printf("%d\n", index);
	}
	return 0;
}
