#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<bool>Vb;
typedef vector<int>Vi;
typedef vector<Vi>Gi;
Gi graph;
Vb visited;
int n, m, u, v;
Vi colors;
stack<int>pile;
stack<int>pila;
int maxcolors = 4;
void asignColor(int nodo) {
	int color = 1;
	while (true) {
		int temp = color;
		for (int i = 0; i < graph[nodo].size(); i++) {
			int ad = graph[nodo][i];
			if (colors[ad] == color) {
				color = colors[ad] + 1;
				break;
			}
		}
		if (temp == color) {
			break;
		}
	}
	colors[nodo] = color;
}
void DFSbactrack(int nodo)
{
	asignColor(nodo);
	visited[nodo] = true;
	for (int i = 0; i < graph[nodo].size(); i++)
	{
		int ad = graph[nodo][i];
		if (visited[ad] == false)
			DFSbactrack(ad);
		ad = 0;
	}
	pila.push(nodo);
}
int main()
{
	Vi res = Vi();
	Vi resp = Vi();
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		scanf("%d", &m);
		graph = Gi(n);
		colors = Vi(n, 0);
		visited = Vb(n, false);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				DFSbactrack(i);
			}
		}
		int max = 0;
		for (int n = 0; n < colors.size(); n++) {
			if (colors.at(n) > max) {
				max = colors.at(n);
			}
		}
		if (max <= 2) {
			printf("BICOLORABLE.\n");
		}
		else {
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}
