#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int t, n, d, q, x, sumtimes, si, j;
	char s[303];
	vector<int> remainDistance, times;
	scanf("%d", &t);
	while (t) {
		scanf("%d %d\n", &n, &d);
		int l = 0;
		while (true) {
			s[l++] = getchar();
			if (s[l - 1] == '\n') {
				l--;
				break;
			}
		}
		scanf("%d", &q);
		for (int k = 0; k < q; k++) {
			priority_queue<ii, vector<ii>, greater<ii>>order;
			scanf("%d", &x);
			sumtimes = 0;
			times = vector<int>();
			remainDistance = vector<int>(n, d);
			for (int i = 0; i < l; i++) {
				si = (int)(s[i] - '0'), j = si - 1;
				if (i + 1 >= 1 + j * x && s[j]) {
					remainDistance[j]--;
					if (!remainDistance[j]) {
						order.push({ i + 1 - (j * x), si });
						times.push_back(i + 1 - (j * x));
						sumtimes += i + 1 - (j * x);
					}
				}
				if (times.size() == n) break;
			}
			if (times.size() > 0) {
				sort(times.begin(), times.end());
				double median = times.size() % 2 == 1 ? times[times.size() / 2] : (double)((double)times[times.size() / 2] + (double)times[times.size() / 2 - 1]) / 2.0;
				double mean = (double)sumtimes / times.size();
				double aux = 0;
				for (int i = 0; i < times.size(); i++)
					aux += pow(times[i] - mean, 2);
				double standardev = sqrt(aux / (times.size() - 1));
				double index = abs(3 * (mean - median) / standardev);
				if (index >= 0.20f || times.size() < n || index != index) {
					printf("INVALID SIMULATION\n");
				}
				else {
					printf("ORDER OF RACING:");
					while (!order.empty()) {
						printf(" %d", order.top().second);
						order.pop();
					}
					printf("\n");
				}
			}
			else {
				printf("INVALID SIMULATION\n");
			}
		}
		t--;
	}
	return 0;
}