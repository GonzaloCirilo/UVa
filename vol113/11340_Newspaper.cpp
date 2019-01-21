#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int n, k, m, cost;
	char rune;
	scanf("%d\n", &n);
	while (n--) {
		map<char, int>table;
		scanf("%d\n", &k);
		//getchar();
		while (k--) {
			scanf("%c %d\n", &rune, &cost);
			table.insert({ rune,cost });
		}
		scanf("%d\n", &m);
		double ans = 0.0;
		while (m) {
			rune = getchar();
			if (rune == '\n') {
				m--;
				continue;
			}
			ans += table[rune];
		}
		ans /= 100;
		printf("%.2f$\n", ans);
	}
	return 0;
}