#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef vector<vector<int>>vvi;
vector<int>pset;
vvi at, type; vector<int>vd;
int n, c, k, a, aux, nele = 0;
void init(int n) {
	pset = vector<int>(n);
	nele = n-1;
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
		pset[findset(a)] = findset(b);
		nele--;
	}
}
bool check(int ev) {
	bool aux = false;
	init(n);
	for (int i = 0; i < c; i++) {
		if (type[i].size()>1) {
			for (int j = 0; j < type[i].size(); j++) {
				int u = type[i][j], v, aux = j - 1;
				if (j == 0)aux = type[i].size() - 1;
				v = type[i][aux];
				if (u != ev&&v != ev)
					unionset(u, v);
			}			
		}
	}
	return nele==1;
}
int main() {
	while (scanf("%d %d", &n, &c) != EOF) {
		at = vvi(n);int m = 9999999;
		init(c);
		vd = vector<int>(c,0);
		type = vvi(c);
		for (int ca = 0; ca < c; ca++) {
			scanf("%d", &k);
			if (k == 0)nele--;
			type[ca] = vector<int>(k);
			for (int j = 0; j < k; j++) {
				scanf("%d", &aux);
				type[ca][j] = aux;
				at[aux].push_back(ca);
				vd[ca] += 2;
				if (at[aux].size() == 2) {
					vd[at[aux][0]]--;
					vd[at[aux][1]]--;
					unionset(at[aux][0], at[aux][1]);
				}
			}
		}
		int v = nele; set<int>s;
		int count = 0;
		for (int i = 0; i < c; i++) {
			if (vd[i] % 2 != 0) {
				count++;
				for (int j = 0; j < type[i].size(); j++) {
					s.insert(type[i][j]);
				}
			}
		}
		if (v != 0 || count>2) {
			printf("-1\n");
		}
		else if (count == 0) {
			printf("0\n");
		}
		else {
			for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
				if (check(*it)) {
					m = *it;
					break;
				}
			}
			printf("%d\n", m);
		}
	}
	return 0;
}
/*
8 6
3 1 2 7
3 0 1 3
2 2 3
3 0 4 6
2 4 5
2 5 6
6 5
2 2 1
3 1 0 5
2 3 4
2 4 5
3 0 3 2*/