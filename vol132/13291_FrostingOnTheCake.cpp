#include <stdio.h>
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
	long long colors[3], ans[3], row, col, n;
	while (fastscan(n)) {
		for (int i = 0; i < 3; i++) {
			colors[i] = 0;
			ans[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			fastscan(col);
			colors[i % 3] += col;
		}
		for (int i = 0; i < n; i++) {
			fastscan(row);
			ans[(0 + i) % 3] += colors[0] * row;
			ans[(1 + i) % 3] += colors[1] * row;
			ans[(2 + i) % 3] += colors[2] * row;
		}

		printf("%lld %lld %lld\n", ans[1], ans[2], ans[0]);
	}
	return 0;
}