#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int nQuestions;
typedef vector<char>Vc;
typedef vector<int>Vi;
typedef vector<Vi>G;
G graph, revgraph;
char u1, u2, u3, u4, u5, v;
stack<int>pile; int cont;
vector<vector<char>>resp;
vector<bool>visited;
struct OrderFirst
{
	bool operator() (Vc const &a, Vc const &b) { return a[0] > b[0]; }
};
void DFS(int nodo)
{
	visited[nodo] = true;
	for (int i = 0; i < graph[nodo].size(); i++)
	{
		int ad = graph[nodo][i];
		if (visited[ad] == false)
			DFS(ad);
		ad = 0;
	}
	pile.push(nodo);
}
void DFS_rev(int nodo)
{
	visited[nodo] = true;
	resp[cont].push_back((char)(nodo + 65));
	for (int i = 0; i < revgraph[nodo].size(); i++)
	{
		int ad = revgraph[nodo][i];
		if (visited[ad] == false)
			DFS_rev(ad);
	}
}
int main()
{
	int c = 0;
	while (true)
	{
		visited = vector<bool>(27, true);
		scanf("%d", &nQuestions);
		if (nQuestions == 0) {
			break;
		}
		if (c > 0)printf("\n");
		graph = G(27);
		revgraph = G(27);
		for (int i = 0; i < nQuestions; i++) {
			scanf(" %c %c %c %c %c %c", &u1, &u2, &u3, &u4, &u5, &v);
			int a = (int)v - 65;
			vector<int>options = { (int)u1 - 65,(int)u2 - 65,(int)u3 - 65,(int)u4 - 65,(int)u5 - 65 };
			sort(options.begin(), options.end());
			for (int j = 0; j<options.size(); j++) {
				graph[a].push_back(options[j]);
				revgraph[options[j]].push_back(a);
				visited[options[j]] = false;
			}
		}
		for (int i = 0; i<27; i++) {
			if (!visited[i])
				DFS(i);
		}
		visited = vector<bool>(27);
		resp = vector<vector<char>>(27);
		priority_queue<Vc, vector<Vc>, OrderFirst>pq;
		cont = 0;
		while (!pile.empty()) {
			int nodo = pile.top(); pile.pop();
			if (visited[nodo] != true) {
				DFS_rev(nodo);
				sort(resp[cont].begin(), resp[cont].end());
				pq.push(resp[cont]);
				cont++;
			}
		}
		while (!pq.empty()) {
			Vc aux = pq.top(); pq.pop();
			for (int i = 0; i < aux.size(); i++) {
				i == 0 ? printf("%c", aux[i]) : printf(" %c", aux[i]);
			}
			printf("\n");
		}
		c++;
	}
	return 0;
}