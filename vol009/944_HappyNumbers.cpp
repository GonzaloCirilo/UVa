#include <stdio.h>
#include <set>;
using namespace std;
typedef pair<int, int> ii;
ii dp[100000];
set<int> ns;
int recursive(int n) {
	if (dp[n].first == 1 || dp[n].first == -1)
		return dp[n].first;
	if (n == 1) {
		dp[n] = { 1,1 };
		return 1;
	}
	if (!ns.insert(n).second) {
		dp[n] = { -1,0 };
		return -1;
	}
	int aux = n, newN = 0;
	while (aux) {
		int s = aux % 10; aux /= 10;
		s *= s;
		newN += s;
	}
	dp[n] = { recursive(newN),dp[newN].second + 1 };
	return dp[newN].first;
}
int main() {
	for (int i = 1; i < 100000; i++) {
		if (dp[i].first == 0) {
			ns.clear();
			recursive(i);
		}
	}
	int n, m;
	int cont = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (cont++)
			printf("\n");
		for (int i = n; i <= m; i++) {
			if (dp[i].first == 1)
				printf("%d %d\n", i, dp[i].second);
		}
	}
	return 0;
}