#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
	double n, m;
	while (scanf("%lf %lf", &n, &m) != EOF) {
		double l = 10000.0, div = l / n, newDiv = l / (n + m), ans = 0;
		for (int i = 1; i < n; i++) {
			double sector = i * div, newSector = floor((sector) / newDiv + 0.5);
			ans += fabs(sector - newSector * newDiv);
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}