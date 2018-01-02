#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int>Vi;
typedef vector<Vi>G;
G graph;
vector<bool>visited;
stack<int>s;
void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int ad = graph[node][i];
		if (visited[ad] == false) {
			DFS(ad);
		}
	}
	s.push(node);
}
int main() {
	int n, m;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		graph = G(n);
		visited = vector<bool>(n);
		s = stack<int>();
		int i, j;
		for (int  k= 0; k < m; k++) {
			scanf("%d %d", &i, &j);
			i--, j--;
			graph[i].push_back(j);
		}
		for (int i = 0; i<n; i++) {
			if(!visited[i])
				DFS(i);
		}
		while (!s.empty()) {
			printf("%d ", s.top()+1); s.pop();
		}
		printf("\n");
	}
}