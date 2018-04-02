#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>G;
G graph;
int main(){
	int t, p, d, u, v;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		if(i!=0)
			printf("\n");
		scanf("%d %d", &p, &d);
		graph = G(p);
		for(int j = 0; j < d; j++){
			scanf("%d %d", &u, &v);
			graph[v].push_back(u);
			graph[u].push_back(v);
		}
		queue<int>q;
		vector<int> ans = vector<int>(p,-1);
		q.push(0);
		ans[0] = 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int j = 0; j < graph[node].size(); j++){
				if(ans[graph[node][j]] == -1){
					ans[graph[node][j]] = ans[node] + 1;
					q.push(graph[node][j]);
				}
			}
		}
		for(int j = 1; j < p; j++)
			printf("%d\n", ans[j]);

	}
	return 0;
}