#include <stdio.h>
#include <vector>
#include <algorithm>
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
	//int ndigits = max_element(arr, arr + y)->first;

	for (int exp = 1; maxe / exp > 0; exp *= 10)
		countSort(y, exp);
}
int main() {
	int n, m, u, v, w;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		init(n);
		int max = 0;
		for (int mi = 0; mi < m; mi++) {
			scanf("%d %d %d", &u, &v, &w);
			arr[mi] = { w,{ u,v } };
			max = max < w ? w : max;
		}
		int cont = 0;
		int ans = 0;
		radixSort(m, max);
		//while (!pq.empty() && cont != n - 1) {
		for (int mi = 0; mi < m && cont != n -1; mi++){
			iii aux = arr[mi];
			if (!isSameSet(aux.second.first, aux.second.second)) {
				unionset(aux.second.first, aux.second.second);
				ans = aux.first;
				cont++;
			}
		}
		if (cont == n - 1 && m >= n - 1)
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
