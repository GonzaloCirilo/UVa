#include <stdio.h>
using namespace std;
int main() {
	int t, n, x, inc, dec;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		inc = 0, dec = 0;
		scanf("%d", &n);
		int ant = -1;
		while (n) {
			scanf("%d", &x);
			if (ant < x) {
				inc++;
			}
			else if (ant > x) {
				dec++;
			}
			ant = x;
			n--;
		}
		printf("Case %d: %d %d\n", i, inc - 1, dec);
	}
	return 0;
}