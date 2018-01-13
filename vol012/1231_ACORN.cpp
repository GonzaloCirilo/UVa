#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int c, t, h, f, a, n;
vvi forest; vi dp;
int main() {
	scanf("%d", &c);
	for (int ca = 0; ca < c; ca++) {
		scanf("%d %d %d", &t, &h, &f);
		forest = vvi(t, vi(h + 1, 0));
		dp = vi(h + 1, 0);
		for (int i = 0; i < t; i++) {
			scanf("%d", &a);
			for (int j = 0; j < a; j++) {
				scanf("%d", &n);
				forest[i][n]++;
			}
		}
		for (int j = 1; j <= h; j++) {
			for (int i = 0; i<t; i++) {
				int flyh = j - f;
				if (flyh < 0)flyh = 0;
				forest[i][j] += forest[i][j - 1] < dp[flyh] ? dp[flyh] : forest[i][j - 1];
				dp[j] = forest[i][j] < dp[j] ? dp[j] : forest[i][j];
			}
		}
		printf("%d\n", dp[h]);
	}
	scanf("%d", &c);
	return 0;
}