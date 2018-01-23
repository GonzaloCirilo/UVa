#include <stdio.h>
#include <vector>
#include <stack>
#include <list>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool>Vb;
Vb visited;
int cases, ndominoes, lines, u, v;
Gi graph;
stack<int>snode, pile;
void DFS() {
	while (!snode.empty()) {
		int node = snode.top();
		snode.pop();
		if (visited[node]) {
			pile.push(node);
			continue;
		}
		visited[node] = true;
		snode.push(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int ad = graph[node][i];
			if (visited[ad] == false) {

				snode.push(ad);
			}
			ad = 0;
		}
	}
}
int main()
{
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		scanf("%d %d", &ndominoes, &lines);

		graph = Gi(ndominoes);
		for (int j = 0; j < lines; j++) {

			scanf("%d %d", &u, &v);
			u--; v--;
			graph[u].push_back(v);
		}
		visited = Vb(ndominoes, false);
		int components = 0;
		for (int j = 0; j < ndominoes; j++) {
			if (!visited[j]) {
				snode.push(j);
				DFS();
			}

		}
		visited = Vb(ndominoes, false);
		//In this case the second DFS is applied to the original graph
		while (!pile.empty()) {
			int node = pile.top(); pile.pop();
			if (visited[node] != true) {
				components++;
				snode.push(node);
				DFS();
			}
		}
		printf("%d\n", components);
	}
	return 0;
}
