#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int t, n, s, e, m;
vector<int> se, p, a, ap, deathe;
vector<vector<int> > dp, cut;
void LIS() {
	a = vector<int>(n);
	ap = vector<int>(n, 0);
	int len = 0;
	for (int i = 1; i < n; i++) {
		if (se[a[len]] < se[i]) {
			len++;
			a[len] = i;
			ap[i] += len;
		} else {
			int index = 0;
			s = 0, e = len;
			while (s <= e) {
				m = (s + e) / 2;
				if (se[a[m]] < se[i] && se[i] <= se[a[m + 1]] && m < len) {
					index = m + 1;
					break;
				} else if (se[a[m]] < se[i]) {
					s = m + 1;
				} else {
					e = m - 1;
				}
			}
			ap[i] = ap[a[index]];
			a[index] = i;
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int ta = 0; ta < t; ta++) {
		scanf("%d", &n);
		se = vector<int>(n);
		p = vector<int>(n, 1);
		for (int j = 0; j < n; j++) {
			scanf("%d", &se[j]);
		}
		LIS();
		reverse(se.begin(), se.end());
		for (int i = 0; i < p.size(); i++) {
			p[i] += ap[i];
		}
		LIS();
		reverse(ap.begin(), ap.end());
		for (int i = 0; i < p.size(); i++) {
			p[i] += ap[i];
		}
		deathe = vector<int>(n + 1, 0);
		for (int j = 0; j < p.size(); j++) {
			if (j == 0)
				deathe[j + 1] = p[j];
			else
				deathe[j + 1] = p[j] + deathe[j];
		}
		dp = vector<vector<int> >(n + 1, vector<int>(n + 1, -1));
		cut = vector<vector<int> >(n + 1, vector<int>(n + 3, 0));
		for (int i = 0; i <= n; i++) {
			cut[i][i + 2] = i + 1;
			cut[i][i + 1] = i;
		}
		for (int k = 0; k <= n; k++) {
			for (int l = 0; l <= (n - k); l++) {
				int r = l + k;
				if (k < 2) {
					dp[l][r] = 0;
					cut[l][r] = l;
					continue;
				}
				dp[l][r] = 99999999;
				int k1 = cut[l][r - 1];
				int k2 = cut[l + 1][r];
				for (int j = k1; j <= k2; j++) {
					int newcost = dp[l][j] + dp[j][r] + (deathe[r] - deathe[l]);
					if (dp[l][r] > newcost) {
						dp[l][r] = newcost;
						cut[l][r] = j;
					}
				}
			}
		}
		printf("Case %d: %d\n", ta + 1, dp[0][n]);
	}
	return 0;
}
