#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
vvi dp;
vector<int> w;
int solve(int a, int b) {
	if (b <= a)return 0;
	if (b - a == 1)return w[a] * 2;
	if (b - a == 2)return w[a + 1] * 3;
	if (dp[a][b] != -1) return dp[a][b];
	int ans = 999999;
	for (int i = a; i <= b; i++) {
		int aux = w[i] * (b - a + 1) + solve(a, i - 1) + solve(i + 1, b);
		if (aux < ans)ans = aux;
	}
	dp[a][b] = ans;
	return ans;
}
int main() {
	int t, n, k;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		dp = vvi(n + 1, vector<int>(n + 1, -1));
		w = vector<int>(n + 1);
		for (int j = 0; j < w.size(); j++) {
			w[j] = k + j;
		}
		printf("Case %d: %d\n", i + 1, solve(1, n));
	}
	return 0;
}