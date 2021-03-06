#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char a[1001], b[1001];
int dp[1001][1001];
int len() {//Iterative
	int la = strlen(a), lb = strlen(b);
	for (int i = 1; i < la; i++) {
		for (int j = 1; j < lb; j++) {
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i - 1][j - 1] - 1000000;
			dp[i][j] = max(dp[i][j],max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	return dp[la - 1][lb - 1];
}
int main() {
	while (fgets(a,1001,stdin)) {
		fgets(b, 1001, stdin);
		printf("%d\n", len());
	}
	return 0;
}