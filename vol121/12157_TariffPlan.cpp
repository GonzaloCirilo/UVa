#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int t, n, ni, mile, juice;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		mile = 0, juice = 0;
		printf("Case %d: ", i);
		while (n--) {
			scanf("%d", &ni);
			mile += ((ni / 30) + 1) * 10;
			juice += ((ni / 60) + 1) * 15;
		}
		if (mile < juice)
			printf("Mile ");
		else if (mile > juice)
			printf("Juice ");
		else
			printf("Mile Juice ");
		printf("%d\n", min(mile, juice));
	}
	return 0;
}