#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int n, r, b, Cd, d[12], C[12][12],l[12],u[12];
	char token[11];
	scanf("%d %d\n", &n, &r);
	map<string, int>m;
	for (int i = 0; i < n; i++) {
		scanf("%s", &token);
		m.insert({ string(token),i });
		scanf("%d %d %d", &b, &Cd, &d[i]);
		C[i][d[i]] = Cd;
		for (int j = 1; j <= d[i]; j++) 
			scanf("%d %d", &l[j], &u[j]);
		
		C[i][0] = b - (C[i][d[i]] * l[d[i]]);
		for (int j = d[i] - 1; j > 0; j--) {
			C[i][j] = C[i][j + 1] * (u[j + 1] - l[j + 1] + 1);
			C[i][0] -= (C[i][j] * l[j]);
		}
		getchar();
	}
	for (int i = 0; i < r; i++) {
		scanf("%s", &token);
		int ind = m[string(token)], k, ans = C[ind][0];
		printf("%s[", token);
		for (int i = 0; i < d[ind]; i++) {
			if (i)
				printf(", ");
			scanf("%d", &k);
			printf("%d", k);
			ans += C[ind][i + 1] * k;
		}
		printf("] = %d\n", ans);
	}
	return 0;
}