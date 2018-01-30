#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
vector<int> pset; int ans;
void init(int n) {
	pset = vector<int>(n,-1);	ans = n;
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
	if (!isSameSet(a, b)){
		pset[findset(a)] = findset(b);
		ans--;
	}
}
int main() {
	int n, m, i, j;
	int cases = 1;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		init(n);
		for (int k = 0; k < m; k++) {
			scanf("%d %d", &i, &j);
			i--, j--;
			unionset(i, j);
		}
		printf("Case %d: %d\n", cases, ans);
		cases++;
	}
	return 0;
}
