#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, less<ii> >qii;
typedef vector<qii>G;
G graph;
int l = 0, node = 0;
int main(){
	int n, m, u, v, ta;
	vector<int> learningu, ac_lu;
	scanf("%d", &ta);
	learningu = vector<int>(102,0);
	for(int t = 0; t < ta; t++){
		scanf("%d %d", &n, &m);
		graph = G(n);
		for(int i = 0; i < n; i++){
			scanf("%d", &learningu[i]);
		}
		for(int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			graph[u].push({ learningu[v],v });
		}
		l = 0; node = 0;
		while(!graph[node].empty()){
			l += graph[node].top().first;
			node = graph[node].top().second;
		}
		printf("Case %d: %d %d\n", t + 1, l, node);
	}
	return 0;
}
