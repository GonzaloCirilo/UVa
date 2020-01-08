#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> G;

bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}

long long djkstra(int s, G graph, int nele){
    priority_queue<ii> pq;

    vector<int> weights = vector<int>(nele, 1410065407);
    weights[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        ii node = pq.top(); pq.pop();
        if(weights[node.second] >= node.first){
            for(int i = 0; i < graph[node.second].size(); i++){
                int newWeight = node.first + graph[node.second][i].first;
                if(weights[graph[node.second][i].second] > newWeight){
                    weights[graph[node.second][i].second] = newWeight;
                    pq.push({ newWeight, graph[node.second][i].second});
                }
            }
        }
    }
    //printf("====%d\n", weights[t]);
    long long ans = 0;
    for(int i = 0; i < nele; i++){
        ans += weights[i];
    }
    return ans;
}

int main(){
    int n, p, q, u, v, w;
    fastScan(n);
    while(n--){
        fastScan(p);
        fastScan(q);
        G g = G(p);
        G rg = g;
        while(q--){
            fastScan(u);
            fastScan(v);
            u--;v--;
            fastScan(w);
            g[u].push_back({w, v});
            rg[v].push_back({w, u});
        }

        long long ans = djkstra(0, g, p) + djkstra(0, rg, p) ;   

        printf("%lld\n", ans);
    }
    return 0;
}