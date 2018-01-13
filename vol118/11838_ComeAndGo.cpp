#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<bool> Vb;
typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef stack<int> Si;
int n, m, v, w, p;
Gi graph, revgraph;
Vb visited, revvisited;
Si stacks;
Si revstacks;
void DFS(int node)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int ad = graph[node][i];
		if (visited[ad] == false)
			DFS(ad);
		ad = 0;
	}
	stacks.push(node);
}
void DFSRev(int node)
{
	visited[node] = true;
	for (int i = 0; i < revgraph[node].size(); i++)
	{
		int ad = revgraph[node][i];
		if (visited[ad] == false)
			DFSRev(ad);
	}
	revstacks.push(node);
}
int main()
{
	vector<int>res;
	while (true) {
		scanf("%d %d", &n, &m);
		graph = Gi(n);
		revgraph = Gi(n);
		visited = Vb(n, false);
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &v, &w, &p);
			v--; w--;
			graph[v].push_back(w);
			revgraph[w].push_back(v);
			if (p == 2) {
				graph[w].push_back(v);
				revgraph[v].push_back(w);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i])
				DFS(i);
		}
		visited = Vb(n, false);
		int components = 0;
		while (!stacks.empty()) {
			int node = stacks.top(); stacks.pop();
			if (visited[node] != true) {
				components++;
				DFSRev(node);
			}
		}
		if (components == 1) {
			printf("%d\n", 1);
		}
		else {
			printf("%d\n", 0);
		}
	}
	return 0;
}
