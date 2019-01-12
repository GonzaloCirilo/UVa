#include <stdio.h>
int sumDigits(long long n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int solve(long long n) {
	if (n < 10)
		return n;
	return solve(sumDigits(n));
	
}
int main() {
	long long n;
	while (scanf("%lld", &n) && n) {
		printf("%d\n",solve(n));
	}
	return 0;
}