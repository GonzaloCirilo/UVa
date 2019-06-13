#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int visited[26][26];
G graph;
int maxe = 0;
void dfs(int node, int depth){
	maxe = maxe < depth ? depth : maxe;
	for(int i = 0; i < graph[node].size(); i++){
		int newNode = graph[node][i];
		if(visited[node][newNode] == 0){
			visited[node][newNode] = 1;
			visited[newNode][node] = 1;
			dfs(newNode, depth + 1);
			visited[node][newNode] = 0;
			visited[newNode][node] = 0;

		}
	}
}

int main(){
	int n, m, u, v;
	while(scanf("%d %d", &n, &m) && (n || m)){
		graph = G(n, vi());
		for(int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			visited[u][v] = 0;
			visited[v][u] = 0;
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			maxe = 0;
			dfs(i, maxe);
			ans = ans < maxe ? maxe : ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}//539