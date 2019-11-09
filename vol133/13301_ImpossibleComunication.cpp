#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
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
int main(){
    int n, m, k, u, v, ai;
	G graph, rev;
	vi visited;
    while (fastScan(n)){
		graph = G(n, vector<int>());
		rev = G(n, vector<int>());
		visited = vi(n, 0);
        fastScan(m);
        for(int i = 0; i < m; i++){
            fastScan(k);
			if(k == 1){
				fastScan(u);
				fastScan(v);
				u--;v--;
				graph[u].push_back(v);
				rev[v].push_back(u);
			}else{
				fastScan(ai); ai--;
				int prev = ai, init = ai;
				for(int i = 0; i < k - 1; i++){
					fastScan(ai); ai--;
					graph[prev].push_back(ai);
					rev[ai].push_back(prev);
					prev = ai;
				}
				graph[ai].push_back(init);
				rev[init].push_back(ai);
			}
        }	
		stack<int> topo;
		for (int i = 0; i < n; i++){
			if (!visited[i]) {
				stack<int> s;
				s.push(i);
				while (!s.empty()) {
					int node = s.top(); s.pop();
					if (visited[node]) {
						topo.push(node);
						continue;
					}
					visited[node] = true;
					s.push(node);
					for (int j = 0; j < graph[node].size(); j++) {
						if (!visited[graph[node][j]]) {
							s.push(graph[node][j]);
						}
					}
				}
			}
		}
		visited = vi(n,0);

		int node = topo.top(); topo.pop();
			if (!visited[node]) {
				stack<int> s;
				s.push(node);
				visited[node] = 1;
				while (!s.empty()){
					int n = s.top(); s.pop();
					for (int i = 0; i < rev[n].size(); i++) {
						if (!visited[rev[n][i]]) {
							visited[rev[n][i]] = 1;
							s.push(rev[n][i]);
						}
					}
					topo.push(n);
				}
			}
		bool ans = true;
		for(int i = 0; i < n; i++){
			ans = ans && visited[i] != 0;
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
    }    
}