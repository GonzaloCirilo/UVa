#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef vector<vector<int>>vvi;
int vd[10002];
vvi at; 
vector<int> type[10002], pset;
int n, c, k, a, aux, nele = 0;
void init(int n) {
	pset = vector<int>(n, -1);
	nele = n-1;
}
int findset(int nodo) {
	if (-1 == pset[nodo])
		return nodo;
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
				int u = type[i][j], v = j - 1 >= 0?j -1:type[i].size() - 1;
				v = type[i][v];
				if (u != ev&&v != ev)
					unionset(u, v);
			}			
		}
	}
	return nele == 1;
}
int main() {
	while (scanf("%d %d", &n, &c) != EOF) {
		at = vvi(n);
		int m = 9999999;
		init(c);
		for (int ca = 0; ca < c; ca++) {
			vd[ca] = 0;
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