// 990-DivingGold.cpp : main project file.
#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
vector<ii>tesoros;
vector<int>costo;
int aire, w, n;
vector<vector<int>>taken;
vector<vector<int>>table;
vector<int>lineataken;
int DP(int tempo,int n) {
	if (n<0||tempo <= 0)return 0;
	if (table[n][tempo] != -1)return table[n][tempo];
	int ti=tempo>=costo[n]?DP(tempo - costo[n], n - 1)+tesoros[n].second:0, nti= DP(tempo, n - 1);
	ti>= nti ? taken[n][tempo] = 1 : taken[n][tempo] = 0;
	return ti> nti ? table[n][tempo]=ti : table[n][tempo]=nti;
}
int main()
{
	int first = 0;
	while (scanf("%d %d", &aire, &w) ==2) {
		scanf("%d", &n);
		tesoros = vector<ii>(n);
		costo = vector<int>(n);
		lineataken = vector<int>(n);
		table = vector<vector<int>>(31, vector<int>(1001,-1));
		taken = vector<vector<int>>(31, vector<int>(1001, 0));
		int d, val;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &d, &val);
			tesoros[i] = { d,val };
			costo[i] = w * d * 3;
		}
		if (first == 0) {
			first = 1;
		}
		else {
			printf("\n");
		}
		printf("%d\n", DP(aire, n - 1));
		int numtaken = 0, a = aire;
		for (int i = n; i >=0; i--) {
			if (a < 0)continue;

			if (taken[i][a] == 1&& a - costo[i]>=0) {
				numtaken++;
				a -= costo[i];
				lineataken[i] = 1;
			}
			
		}
		printf("%d\n", numtaken);
		for (int i = 0; i < lineataken.size(); i++) {
			if (lineataken[i] == 1)
				printf("%d %d\n", tesoros[i].first, tesoros[i].second);
		}
	}
	return 0;
}