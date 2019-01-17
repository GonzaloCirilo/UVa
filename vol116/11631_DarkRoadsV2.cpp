#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> iii;
int m, n, x, y, z;
vector<int>pset;
iii arr[2000001], aux[2000001];
void init() {
	pset = vector<int>(m, -1);
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
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
void countSort(int e) {
	int count[10] = {};
	for (int i = 0; i < n; i++)
		count[(arr[i].first / e) % 10]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		aux[count[(arr[i].first / e) % 10] - 1] = arr[i];
		count[(arr[i].first / e) % 10]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = aux[i];
}
void radixSort() {
	int ndigits = max_element(arr, arr + n)->first;

	for (int exp = 1; ndigits / exp > 0; exp *= 10)
		countSort(exp);
}
int main() {
	while (scanf("%d %d", &m, &n) && n && m) {
		int sumt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			arr[i] = { z,{x,y} };
			sumt += z;
		}
		int mst = 0;
		init();
		//radix sort
		radixSort();
		for (int i = 0; i < n; i++) {
			iii tri = arr[i];
			if (!isSameSet(tri.second.first, tri.second.second)) {
				mst += tri.first;
				unionset(tri.second.first, tri.second.second);
			}
		}
		printf("%d\n", (sumt - mst));
	}
	return 0;
}
