#include <stdio.h>
#include <vector>
using namespace std;
vector<int> pset;
void init(int n) {
	pset = vector<int>(n);
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
		pset[sa] = sb;
	}
}
//primes union the number from input
void factors(int na, int pos) {
	int z = 2;
	int n = na;
	while (z * z <= n) {
		if (n % z == 0) {
			unionset(z, pos);
			n /= z;
		}
		else
			z++;
	}

	if (n > 1)
		unionset(n, pos);
}
int main() {
	int t, n, a, max = -1;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		init(1000001 + n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			if (a > max) max = a;
			factors(a, 1000001 + j);
		}
		int ans = 0;
		for (int j = 1000001; j <1000001 + n; j++) {
			if (pset[j] == j) {//index equals its parents (connected componenets++)
				ans++;
			}
		}
		printf("Case %d: %d\n", i + 1, ans);
	}
	return 0;
}