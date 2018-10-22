#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
typedef pair<double, double> dd;
int main() {
	int l, d, n, x, y;
	while (scanf("%d", &l) != EOF) {
		scanf("%d %d", &d, &n);
		priority_queue<dd, vector<dd>, greater<dd>> pq;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			double extension = sqrt(d * d - y * y);
			double li = x - extension<0 ? 0 : x - extension, ls = x + extension>l ? l : x + extension;
			pq.push({ li,ls });//push limits of each extension
		}
		double min = -1000;
		int ans = 0;
		while (!pq.empty()) {
			dd line = pq.top(); pq.pop();
			if (min < line.first) {
				min = line.second;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}