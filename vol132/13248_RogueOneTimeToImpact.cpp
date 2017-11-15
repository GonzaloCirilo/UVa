#include <stdio.h>
using namespace std;
void main() {
	int test, d1, d2;
	scanf("%d", &test);
	for (int i = 0; i<test; i++) {
		scanf("%d %d", &d1, &d2);
		int time=(int)((float)d1*10.0 / (float)(d2 - d1)) + 10.0;
		printf("%d\n", time);
	}
}
