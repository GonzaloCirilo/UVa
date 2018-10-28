#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
typedef vector<ii>Vii;
typedef vector<Vii>G;
int main(){
	int n,m,c,k;
	vector<int>actoll;
	G grafo;
	while(scanf("%d %d %d %d", &n, &m, &c, &k) != EOF && n && m && c && k){
		grafo = G(n);
		for(int i=0; i<m; i++){
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			grafo[u].push_back({ p,v });
			grafo[v].push_back({ p,u });
		}
		actoll = vector<int>(n, -1);
		actoll[k] = 0;
		priority_queue<ii,vector<ii>,greater<ii>>pq;
		pq.push({ 0,k });
		while(!pq.empty()){
			int node = pq.top().second;
			int weight = pq.top().first;
			pq.pop();
			if(actoll[node] >= weight){
				for(int i=0; i<grafo[node].size(); i++){
					int adnode = grafo[node][i].second;
					int adweight = grafo[node][i].first;
					int newtoll = adweight+weight;
					if(node < c){//Following the defined route
						if(node == adnode-1 &&(actoll[adnode] == -1 || actoll[adnode] > newtoll)){
							actoll[adnode] = newtoll;
							pq.push({ newtoll,adnode });
						}
					}else{
						if(actoll[adnode] == -1 || actoll[adnode] > newtoll){
							actoll[adnode] = newtoll;
							pq.push({ newtoll,adnode });
						}
					}
				}
			}
		}
		printf("%d\n", actoll[c-1]);
	}
	return 0;
}