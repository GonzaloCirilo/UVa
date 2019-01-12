#include <stdio.h>
#include <math.h>
int main() {
	long long s;
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &s);
		if (s == 1)
			printf("1\n");
		else {
			long long aux = (s + 1) / 2;
			printf("%lld\n", aux * aux * 2 - s);
		}
	}
	return 0;
}