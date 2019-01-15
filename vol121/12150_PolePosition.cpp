#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int n, carNum, pos, correct;
	map<int,int>pole;
	while (scanf("%d", &n) && n) {
		pole.clear();
		correct = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &carNum, &pos);
			if (!pole.insert({ i + (pos),carNum }).second || i + (pos) >= n || i + (pos) < 0)
				correct = 0;
		}
		if (correct) {
			for (auto it = pole.begin(); it != pole.end(); it++) {
				if (it != pole.begin())
					printf(" ");
				printf("%d", (*it).second);
			}
		}
		else
			printf("-1");
		printf("\n");
	}
	return 0;
}