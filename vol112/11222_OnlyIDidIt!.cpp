#include <stdio.h>
#include <set>
using namespace std;
int main() {
	int t, n, s, problems;
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		printf("Case #%d:\n", i + 1);
		int f[3][10001] = {};
		set<int> ans[3];
		for (int j = 0; j < 3; j++) {
			scanf("%d", &n);
			while (n--) {
				scanf("%d", &s);
				f[j][s]++;
			}
		}
		for (int j = 0; j < 10001; j++) {
			if (!f[0][j] && !f[1][j] && f[2][j])
				ans[2].insert(j);
			if (!f[1][j] && !f[2][j] && f[0][j])
				ans[0].insert(j);
			if (!f[0][j] && !f[2][j] && f[1][j])
				ans[1].insert(j);
		}
		int max = 0;
		if (ans[0].size() > ans[1].size())
			max = ans[0].size();
		else
			max = ans[1].size();
		if (max < ans[2].size())
			max = ans[2].size();
		for (int j = 0; j < 3; j++) {
			if (max == ans[j].size()) {
				printf("%d %d", j+1, max);
				for (auto it = ans[j].begin(); it != ans[j].end(); it++)
					printf(" %d", *it);
				printf("\n");
			}
		}
	}
	return 0;
}