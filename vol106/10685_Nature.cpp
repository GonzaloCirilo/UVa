#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
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
	int c, r;
	char c1[31], c2[31];
	map<string, int>dict;
	while (scanf("%d %d", &c, &r) && (c || r)) {
		dict.clear();
		for (int i = 0; i < c; i++) {
			scanf("%30s", &c1);
			dict[string(c1)] = i;
		}
		init(c);
		for (int i = 0; i < r; i++) {
			scanf("%30s %30s", &c1, &c2);
			unionset(dict[string(c1)], dict[string(c2)]);
		}
		printf("%d\n", *max_element(nele.begin(), nele.end()));
	}
	return 0;
}
