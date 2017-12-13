#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<bool>Vb;
typedef vector<int>Vi;
typedef vector<Vi>Gi;
Gi grafo;
Vb visitados;
int n, m,u,v;
Vi colors;
stack<int>q;
stack<int>pila;
int maxcolors=4;
//Variantes de coloracion de grafos
//1.Minino de colores para colorear un grafo
void asignarColor(int nodo) {
	int color = 1;
	while (true) {
		int temp = color;
		for (int i = 0; i < grafo[nodo].size(); i++) {
			int adyacente = grafo[nodo][i];
			if (colors[adyacente] == color) {
				color = colors[adyacente] + 1;
				break;
			}
		}
		if (temp == color) {
			break;
		}		
	}
	colors[nodo] = color;
}
void dfsColoring() {
	while (!q.empty()) {
		int nodo = q.top(); q.pop();
		asignarColor(nodo);
		visitados[nodo] = 1;
		for (int i = 0; i < grafo[nodo].size(); i++) {
			int adyacente = grafo[nodo][i];
			if (visitados[adyacente] == 0) {
				q.push(adyacente);
			}
		}
	}
}
void DFSbactrack(int nodo)
{
	asignarColor(nodo);
	visitados[nodo] = true;
	for (int i = 0; i < grafo[nodo].size(); i++)
	{
		int adyacente = grafo[nodo][i];
		if (visitados[adyacente] == false)
			DFSbactrack(adyacente);
		adyacente = 0;//limpiar memoria
	}
	pila.push(nodo);
}
//fin variante 1\*/
bool DFS(int nodo,int color) {
	colors[nodo] = color;
	for (int i = 0;i < grafo[nodo].size();i++)
	{
		int adyacente = grafo[nodo][i];
		if (colors[adyacente] == 0) {
			if (!DFS(adyacente, color*-1)) {
				return false;
				break;
			}
		} else{
			if (colors[adyacente] == color) {
				return false;
				break;
			}
		}
	}							
	return true;
}
int main()
{
	Vi res=Vi();
	Vi resp = Vi();
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		scanf("%d", &m);
		grafo = Gi(n);
		colors = Vi(n, 0);
		visitados = Vb(n, false);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if (!visitados[i]) {
				//q.push(i);

				DFSbactrack(i);
			}
		} 
		int max = 0;
		for (int n = 0; n < colors.size(); n++) {
			if (colors.at(n) > max) {
				max = colors.at(n);
			}
		}		
		if (max<=2) {
			printf("BICOLORABLE.\n");
		}
		else {
			printf("NOT BICOLORABLE.\n");
		}
		
	}

	
	

	return 0;
}
