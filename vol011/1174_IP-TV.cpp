#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<int> pset;
iii arr[1000001], aux[1000001];
void init(int n) {
	pset = vector<int>(n, -1);
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
	pset[findset(a)] = findset(b);
}

void countSort(int y, int e) {
	int count[10] = {};
	for (int i = 0; i < y; i++)
		count[(arr[i].first / e) % 10]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = y - 1; i >= 0; i--) {
		aux[count[(arr[i].first / e) % 10] - 1] = arr[i];
		count[(arr[i].first / e) % 10]--;
	}
	for (int i = 0; i < y; i++)
		arr[i] = aux[i];
}
void radixSort(int y, int maxe) {
	for (int exp = 1; maxe / exp > 0; exp *= 10)
		countSort(y, exp);
}
int main() {
	int n, m, w, t;
	char u[9], v[9];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		scanf("%d\n%d", &m, &n);
		init(m);
		map<string, int> dict;
		int max = 0, cont = 0;
		for (int mi = 0; mi < n; mi++) {
			scanf("%s %s %d", &u, &v, &w);
			if (dict.insert({ string(u),cont }).second)
				cont++;
			if (dict.insert({ string(v),cont }).second)
				cont++;
			arr[mi] = { w,{ dict[u],dict[v] } };
			max = max < w ? w : max;
		}
		cont = 0;
		int ans = 0;
		radixSort(n, max);
		for (int i = 0; i < n && cont != m -1; i++){
			iii aux = arr[i];
			if (!isSameSet(aux.second.first, aux.second.second)) {
				unionset(aux.second.first, aux.second.second);
				ans += aux.first;
				cont++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
