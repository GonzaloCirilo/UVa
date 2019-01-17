#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<int> pset, nele;
void init(int n) {
	pset = vector<int>(n, -1);
	nele = vector<int>(n, 1);
}
int findset(int nodo) {
	if (-1 == pset[nodo])
		return nodo;
	return pset[nodo] = findset(pset[nodo]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
int unionset(int a, int b) {
	if (!isSameSet(a, b)) {
		int pa = findset(a), pb = findset(b);
		pset[pa] = pb;
		nele[pb] += nele[pa];
		nele[pa] = 0;
	}
	return nele[findset(a)];
}
int main() {
	int n, t;
	char u[9], v[9];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d\n%d", &n);
		init(n);
		map<string, int> dict;
		int  cont = 0;
		for (int mi = 0; mi < n; mi++) {
			scanf("%s %s", &u, &v);
			if (dict.insert({ string(u),cont }).second)
				cont++;
			if (dict.insert({ string(v),cont }).second)
				cont++;
			printf("%d\n",unionset(dict[u], dict[v]));
		}
	}
	return 0;
}
