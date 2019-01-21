#include <stdio.h>
void fastscan(int &x) {
	bool neg = false;
	int c = getchar();
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
}
int main() {
	int t, n, p[100001], q[100001];
	fastscan(t);
	for (int i = 1; i <= t; i++) {
		printf("Case %d: ", i);
		fastscan(n);
		for (int j = 0; j < n; j++) 
			fastscan(p[j]);
		int pos = 0;
		for (int j = 0; j < n; j++) {
			fastscan(q[j]);
			pos += p[j] - q[j];
		}
		if (pos < 0) {
			printf("Not possible\n");
			continue;
		}
		pos = 0; int fuel = 0;
		for (int j = 0; j < n; j++) {
			fuel += p[j] - q[j];
			if (fuel < 0) {
				fuel = 0, pos = j + 1;
			}
		}
		printf("Possible from station %d\n", pos + 1);
	}
}