#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n; vector<int> dp = vector<int>(7500,1);
	int cents[5] = { 1, 5, 10, 25, 50 };
	dp[0] = 1;
	for (int i = 1; i < 5; i++) {
		for (int j = cents[i]; j < 7500; j++) {
			dp[j] += dp[j - cents[i]];
		}
	}
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", dp[n]);
	}
	return 0;
}
