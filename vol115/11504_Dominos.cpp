#include <stdio.h>
#include <vector>
#include <stack>
#include <list>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool>Vb;
Vb visitados;
int cases;
int ndominoes, lines;
int u, v;
Gi grafo;
stack<int>snodo,pila;
void DFS() {
	while (!snodo.empty()) {
		int nodo = snodo.top();
		snodo.pop();
		if (visitados[nodo]) {
			pila.push(nodo);
			continue;
		}
		visitados[nodo] = true;
		snodo.push(nodo);
		for (int i = 0; i < grafo[nodo].size(); i++) {
			int adayacente = grafo[nodo][i];
			if (visitados[adayacente] == false) {

				snodo.push(adayacente);
			}
			adayacente = 0;
		}
	}
}


int main()
{
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		scanf("%d %d", &ndominoes, &lines);

		grafo = Gi(ndominoes);
		for (int j = 0; j < lines; j++) {

			scanf("%d %d", &u, &v);
			u--; v--;
			grafo[u].push_back(v);
		}
		visitados = Vb(ndominoes, false);
		int componentes = 0;
		for (int j = 0; j < ndominoes; j++) {
			if (!visitados[j]) {
				snodo.push(j);
				DFS();
			}
			
		}
		visitados = Vb(ndominoes, false);
		//En este caso se varia el algoritmo del Kosaraju aplicando el DFS por segunda vez al grafo original y no al reverso, en el orden que terminaron
		while (!pila.empty()) {
			int nodo = pila.top(); pila.pop();
			if (visitados[nodo] != true) {
				componentes++;
				snodo.push(nodo);
				DFS();
			}
		}
		printf("%d\n", componentes);
	}
    return 0;
}
