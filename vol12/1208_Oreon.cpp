#include <vector>
#include <queue>
#include <functional>
using namespace std;
int cases;
int nodes;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<int>pset;
priority_queue<iii, vector<iii>, greater<iii>>p;
void init() {
	pset = vector<int>(nodes);
	for (int i = 0; i < pset.size(); i++) {
		pset[i] = i;
	}
}
int findset(int nodo) {
	if (nodo == pset[nodo])
		return pset[nodo];
	return pset[nodo] = findset(pset[nodo]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
char convertIntToChar(int n) {
	return (char)n + 65;
}
int main()
{
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		//limpiar la cola
		while (!p.empty()) { p.pop(); }
		scanf("%d", &nodes);
		int r;
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				if (j == nodes - 1) {
					scanf("%d", &r);
				}
				else {
					scanf("%d, ", &r);
				}
				if (j < i && r != 0)p.push({ r,{ j,i } });
			}
		}
		init();
		int cont = 0;
		printf("Case %d:", c+1);
		while (!p.empty() && cont < nodes - 1) {
			auto aux = p.top(); p.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				cont++;
				unionset(aux.second.first, aux.second.second);
				printf("\n%c-%c %d", convertIntToChar(aux.second.first), convertIntToChar(aux.second.second), aux.first);
			}
		}
		printf("\n");
	}
	return 0;
}