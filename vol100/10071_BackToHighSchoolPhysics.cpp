#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int v, t;
	while (scanf("%d %d", &v, &t) == 2) {
		if (t == 0) {
			printf("%d\n", 0);
			continue;
		}
		double a = (double)v / (double)t;
		t *= 2;
		int vf = round(((double)a / 2 * pow(t, 2)));
		printf("%d\n", vf);
	}
	return 0;
}
