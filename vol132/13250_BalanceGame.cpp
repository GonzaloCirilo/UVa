#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace std;
int m, w; int64_t ans;
vector<int>tokens = vector<int>(3);
void extgcd(int32_t a, int32_t b, int32_t *gcd, int32_t *x, int32_t *y) {
	if (b == 0) {
		*x = 1; *y = 0; *gcd = a;
		return;
	}
	extgcd(b, a%b, gcd, y, x);
	//update values for x and y
	*y += *x * (-(a / b));
}
int64_t exec(int64_t nw) {
	int32_t gcd, x, y;
	extgcd((int32_t)tokens[0], (int32_t)tokens[1], &gcd, &x, &y);
	if (nw%gcd != 0) return 0;
	//Using bezout identity formula to find other values (for k) of x and y between -m and m
	int64_t xmin = ceil((double)(-m - (x*(nw / gcd))) / (tokens[1] / gcd)), xmax = floor((double)(m - (x*(nw / gcd))) / (tokens[1] / gcd));
	int64_t ymin = ceil((double)(m - (y*(nw / gcd))) / (-tokens[0] / gcd)), ymax = floor((double)(-m - (y*(nw / gcd))) / (-tokens[0] / gcd));
	//Intersection
	if (xmin > xmax || ymin > ymax) return 0;
	xmin < ymin ? xmin = ymin : xmin;
	xmax > ymax ? xmax = ymax : xmax;
	return xmax - xmin + 1;
}
int main()
{
	while (scanf("%d %d", &m, &w) != EOF) {
		ans = 0;
		scanf("%d %d %d", &tokens[0], &tokens[1], &tokens[2]);
		sort(tokens.begin(), tokens.end());
		int maxw = (tokens[0] + tokens[1]) * m;
		for (int i = 0; i <= m; i++) {
			int nw = w + tokens[2] * i;
			long long nw2 = w + tokens[2] * -i;
			if (nw <= maxw && nw >= -maxw)
				ans += exec(nw);
			if (i != 0 && nw2 >= -maxw && nw2 <= maxw)
				ans += exec(nw2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}