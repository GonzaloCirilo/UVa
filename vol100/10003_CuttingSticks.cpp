#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	vector<vector<int>>dp = vector<vector<int>>(1002, vector<int>(1002, 0));
	int l, n;
	vector<int> cuts;
	while (true) {
		scanf("%d", &l);
		if (l == 0)break;
		scanf("%d", &n);
		cuts = vector<int>(n + 2);
		cuts[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cuts[i]);
		}
		cuts[n+1] = l;
		for (int k = 2; k <= n+1; k++) {
			for (int i = 0; i <= (n+1 - k); i++) {
				int aux = i + k;
				dp[i][aux] = 999999;
				for (int j = i + 1; j < aux; j++) {
					int newcost = dp[i][j] + dp[j][aux] + (cuts[aux] - cuts[i]);
					if (dp[i][aux]>newcost)
						dp[i][aux] = newcost;
				}
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}