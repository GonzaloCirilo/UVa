#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
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
    int n, a;
    while(fastScan(n) && n != 0) {
        long long ans = 0;
        int current = 0;
        for (int i = 0; i < n; i++) {
            fastScan(a);
            ans += abs(current);
            current = current + a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}