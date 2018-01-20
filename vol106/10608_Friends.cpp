#include <stdio.h>
#include <vector>
using namespace std;
vector<int>pset, nele;
void init(int n) {
	pset = vector<int>(n);
	nele = vector<int>(n, 1);
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
	if (!isSameSet(a, b)) {
		int sa = findset(a), sb = findset(b);
		nele[sb] += nele[sa];
		nele[sa] = 0;
		pset[sa] = sb;
	}
}
int main() {
	int t, n, m, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		init(n);
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &a, &b);
			a--; b--;
			unionset(a, b);
		}
		int max = -1;
		for (int j = 0; j < nele.size(); j++) {
			if (nele[j]>max) max = nele[j];
		}
		printf("%d\n", max);
	}
	return 0;
}