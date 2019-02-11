#include <stdio.h>
int main() {
	int t, a, b, c, m, n, x[10001], sum[10001];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d %d %d", &a, &b, &c, &m, &n);
		x[0] = a; sum[0] = a; int frequence[10001] = {}, ans = 0;
		if (!(sum[0] % m))
			ans++;
		frequence[sum[0] % m]++;
		
		for (int i = 1; i < n; i++) {
			x[i] = ((x[i - 1] * b + c) % m) + 1;
			sum[i] = (x[i] + sum[i - 1]) % m;
			ans += frequence[sum[i]] + (bool)(!sum[i]);
			frequence[sum[i]]++;
		}

		printf("Case %d: %d\n", i, ans);
	}
	return 0;
}