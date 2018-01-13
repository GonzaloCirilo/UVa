#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
vector<ii>treasures;
vector<int>cost;
int air, w, n;
vector<vector<int>>taken;
vector<vector<int>>table;
vector<int>ltaken;
int DP(int tempo, int n) {
	if (n<0 || tempo <= 0)return 0;
	if (table[n][tempo] != -1)return table[n][tempo];
	int ti = tempo >= cost[n] ? DP(tempo - cost[n], n - 1) + treasures[n].second : 0, nti = DP(tempo, n - 1);
	ti >= nti ? taken[n][tempo] = 1 : taken[n][tempo] = 0;
	return ti> nti ? table[n][tempo] = ti : table[n][tempo] = nti;
}
int main()
{
	int first = 0;
	while (scanf("%d %d", &air, &w) == 2) {
		scanf("%d", &n);
		treasures = vector<ii>(n);
		cost = vector<int>(n);
		ltaken = vector<int>(n);
		table = vector<vector<int>>(31, vector<int>(1001, -1));
		taken = vector<vector<int>>(31, vector<int>(1001, 0));
		int d, val;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &d, &val);
			treasures[i] = { d,val };
			cost[i] = w * d * 3;
		}
		if (first == 0) {
			first = 1;
		}
		else {
			printf("\n");
		}
		printf("%d\n", DP(air, n - 1));
		int numtaken = 0, a = air;
		for (int i = n; i >= 0; i--) {
			if (a < 0)continue;

			if (taken[i][a] == 1 && a - cost[i] >= 0) {
				numtaken++;
				a -= cost[i];
				ltaken[i] = 1;
			}

		}
		printf("%d\n", numtaken);
		for (int i = 0; i < ltaken.size(); i++) {
			if (ltaken[i] == 1)
				printf("%d %d\n", treasures[i].first, treasures[i].second);
		}
	}
	return 0;
}
