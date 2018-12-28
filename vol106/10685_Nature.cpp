#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int pset[5005], nele[5005];
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
		int sa = findset(a), sb = findset(b);
		nele[sb] += nele[sa];
		nele[sa] = 0;
		pset[sa] = sb;
		return nele[sb];
	}
	return 0;
}
int main() {
	int c, r;
	char c1[31], c2[31];
	while (scanf("%d %d", &c, &r) && (c || r)) {
		map<string, int>dict;
		for (int i = 0; i < c; i++) {
			pset[i] = -1;
			nele[i] = 1;
			scanf("%30s", &c1);
			dict[string(c1)] = i;
		}
		int max = 1;
		for (int i = 0; i < r; i++) {
			scanf("%30s %30s", &c1, &c2);
			int u = unionset(dict[string(c1)], dict[string(c2)]);
			max = max < u ? u : max;
		}
		printf("%d\n", max);
	}
	return 0;
}
