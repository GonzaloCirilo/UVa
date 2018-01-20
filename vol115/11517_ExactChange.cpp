#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>vvi;
int main() {
	int t, ac, n;
	vi coins, dp;
	scanf("%d", &t);
	for (int ta = 0; ta < t; ta++) {
		scanf("%d", &ac);
		scanf("%d", &n);
		dp = vi(30001, 999999);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			int c;
			scanf("%d", &c);
			coins.push_back(c);
			for (int j = 30000 - c; j >= 0; j--) {
				if (dp[j] != 999999)
					dp[j + c] = min(dp[j + c], dp[j] + 1);
			}
		}
		while (dp[ac] == 999999)
			ac++;
		printf("%d %d\n", ac, dp[ac]);
	}
	return 0;
}