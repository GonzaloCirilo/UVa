#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<bool> Vb;
typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef stack<int> Si;
int n, m, v, w, p;
Gi grafo, graforev;
Vb visitados, visitadorev;
Si pila;
Si pila_rev;
void DFS(int nodo)
{
	visitados[nodo] = true;
	for (int i = 0; i < grafo[nodo].size(); i++)
	{
		int adyacente = grafo[nodo][i];
		if (visitados[adyacente] == false)
			DFS(adyacente);
		adyacente = 0;
	}
	pila.push(nodo);
}
void DFSRev(int nodo)
{
	visitados[nodo] = true;

	for (int i = 0; i < graforev[nodo].size(); i++)
	{
		int adyacente = graforev[nodo][i];
		if (visitados[adyacente] == false)
			DFSRev(adyacente);
	}
	pila_rev.push(nodo);
}
int main()
{
	vector<int>res;
	while (true) {
		scanf("%d %d", &n, &m);
		grafo = Gi(n);
		graforev = Gi(n);
		visitados = Vb(n, false);
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &v, &w, &p);
			v--; w--;
			grafo[v].push_back(w);
			graforev[w].push_back(v);
			if (p == 2) {
				grafo[w].push_back(v);
				graforev[v].push_back(w);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!visitados[i])
				DFS(i);
		}

		visitados = Vb(n, false);
		int componentes = 0;

		while (!pila.empty()) {
			int nodo = pila.top(); pila.pop();
			if (visitados[nodo] != true) {
				componentes++;
				DFSRev(nodo);
			}
		}
		if (componentes == 1) {
			printf("%d\n", 1);
		}
		else {
			printf("%d\n", 0);
		}

	}
	return 0;
}

