#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long n, people[1000001], dp[1000001];
bool fastscan(long long &x) {
	bool neg = false;
	long long c;
	bool end = (c = getchar()) == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
int main() {
	while (fastscan(n)) {
		if (!n) {
			printf("0\n");
			continue;
		}
		long long prom = 0, i;
		for (i = 0; i < n; i++) {
			fastscan(people[i]);
			prom += people[i];
		}
		prom /= n;
		for (i = 0; i < n; i++)
			dp[i] = prom - people[i];
		for (i = n - 2; i > 0; i--) {
			dp[i] += dp[i + 1];
		}
		dp[0] = 0;
		sort(dp, dp + n);
		long long median = (dp[n / 2] + dp[(n - 1) / 2]) / 2, ans = 0;
		for (i = 0; i < n; i++) {
			dp[i] -= median;
			ans += dp[i] < 0 ? dp[i] * -1 : dp[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}