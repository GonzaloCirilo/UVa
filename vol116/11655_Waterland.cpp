#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int>vi;
typedef vector<long long>vll;
typedef vector<vi>Gi; Gi graph;
vector<bool> visited;
vi s;
void DFS(int node, int t) {
	visited[node] = true;
	if (node == t)return;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int ad = graph[node][i];
		if (visited[ad] == false) {
			DFS(ad, t);
		}
	}
	s.push_back(node);
}
int main() {
	int n, l, t, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &t);
		graph = Gi(l);
		visited = vector<bool>(l);
		s = vi();
		for (int j = 0; j < t; j++) {
			scanf("%d %d", &x, &y);
			graph[x - 1].push_back(y - 1);
		}
		DFS(0, l - 1);
		vll dppaths = vll(l), dpvertex = vll(l);
		dppaths[l - 1] = 1; dpvertex[l - 1] = 1;
		for (int j = 0; j < s.size(); j++) {
			dppaths[s[j]] = 0; 
			for (int k = 0; k < graph[s[j]].size(); k++) {
				if (s[j] != 0) dpvertex[s[j]] += dppaths[graph[s[j]][k]]; //Count the total number of groups that is needed
				dppaths[s[j]] += (dppaths[graph[s[j]][k]] % 100000);
				dpvertex[s[j]] += (dpvertex[graph[s[j]][k]] % 100000);
			}
		}
		printf("Case %d: %lld %lld\n", i + 1, dpvertex[0] % 100000, dppaths[0] % 100000);
	}
	return 0;
}
