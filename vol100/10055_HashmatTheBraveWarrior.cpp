#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
	long long a, b;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		printf("%lld\n", llabs(a - b));
	}
	return 0;
}