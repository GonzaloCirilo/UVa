#include <stdio.h>
#include <vector>
using namespace std;
vector<int>pset, sum, nele, dp;
void init(int n) {
	pset = vector<int>(n);
	nele = vector<int>(n, 1);
	sum = vector<int>(n);
	dp = vector<int>(n);
	for (int i = 0; i < pset.size(); i++) {
		pset[i] = i;
		sum[i] = i + 1;
		dp[i] = i;
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
		sum[sb] += sum[sa];
		nele[sb] += nele[sa];
		nele[sa] = 0;
		sum[sa] = 0;
		pset[sa] = sb;		
	}
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		init(n+m);
		for (int i = 0; i < m; i++) {
			int c, p, q, aux;
			scanf("%d ", &c);
			switch (c) {
			case 1:
				scanf("%d %d", &p, &q);
				p--; q--;
				unionset(dp[p], dp[q]);
				break;
			case 2:
				scanf("%d %d", &p, &q);
				p--; q--;
				int sp, sq;
				sp = findset(dp[p]); sq = findset(dp[q]);
				if (sp != sq) {
					nele[sp] -= 1;
					sum[sp] -= (p + 1);
					dp[p] = n++;
					nele[dp[p]] = 1;
					sum[dp[p]] = p + 1;
					unionset(dp[p], dp[q]);
				}				
				break;
			case 3:
				scanf("%d", &p);
				p--;
				printf("%d %d\n", nele[findset(dp[p])], sum[findset(dp[p])]);
				break;
			}
		}
	}
	return 0;
}