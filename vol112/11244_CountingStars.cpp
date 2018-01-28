#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> G;
typedef vector<bool>Vb;
stack<int>snode, stacks;
G graph;
Vb visited;
void DFS(int n) {
	snode.push(n);
	while (!snode.empty()) {
		int node = snode.top();
		snode.pop();
		if (visited[node]) {
			stacks.push(node);
			continue;
		}
		visited[node] = true;
		snode.push(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int ad = graph[node][i];
			if (visited[ad] == false)
				snode.push(ad);
		}
	}
}
int RevDFS(int n) {//is the same graph since the graph is undirected
	int ncount = 0;
	snode.push(n);
	while (!snode.empty()) {
		int node = snode.top();
		snode.pop();
		if (visited[node]) {
			ncount++;
			continue;
		}
		visited[node] = true;
		snode.push(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int ad = graph[node][i];
			if (visited[ad] == false)
				snode.push(ad);
		}
	}
	return ncount;
}
int main() {
	int r, c, n;
	char token;
	vector<ii> moves = { { -1,0 },{ -1,-1 },{ 0,-1 },{-1,1} };
	G sky = G(101, vi(101));
	while (scanf("%d %d", &r, &c) && r && c) {
		n = 0;
		graph.clear();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("\n%c", &token);
				sky[i][j] = -1;
				if (token == '*') {
					sky[i][j] = n++;
					graph.push_back(vi());
					for (int k = 0; k < 4; k++) {
						int di = i + moves[k].first, dj = j + moves[k].second;
						if (di >= 0 && dj >= 0  && dj < c && sky[di][dj] != -1) {
							graph[sky[i][j]].push_back(sky[di][dj]);
							graph[sky[di][dj]].push_back(sky[i][j]);
						}
					}
				}
			}
		}
		visited = Vb(n , 0);
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		visited = Vb(n + 1, 0);
		int ans = 0;
		while (!stacks.empty()) {
			int node = stacks.top(); stacks.pop();
			if (!visited[node]) {
				if(RevDFS(node) == 1)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
