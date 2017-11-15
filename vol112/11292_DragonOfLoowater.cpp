#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int n, m;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)break;
		priority_queue<int, vector<int>, greater<int>>pqdragon;
		priority_queue<int, vector<int>, greater<int>>pqknights;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			pqdragon.push(a);
		}
		for (int i = 0; i < m; i++) {
			int a;
			scanf("%d", &a);
			pqknights.push(a);
		}
		int payout = 0;
		if (n > m) {
			printf("Loowater is doomed!\n");
			continue;
		}
		bool isKilled = true;
		while (!pqdragon.empty()) {
			int diameter = pqdragon.top(); pqdragon.pop();
			bool killed = false;
			while (!pqknights.empty()) {
				int height = pqknights.top(); pqknights.pop();
				if (diameter <= height) {
					payout += height;
					killed = true;
					break;
				}
			}
			if (killed == false) {
				printf("Loowater is doomed!\n");
				isKilled = false;
				break;
			}
		}
		if(isKilled==true)
			printf("%d\n", payout);

	}
}
