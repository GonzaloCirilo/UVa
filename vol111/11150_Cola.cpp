#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", n + (int)floor(n/2));
	}
	return 0;
}