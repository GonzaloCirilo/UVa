#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> field;
int main()
{
	int nights;
	scanf("%d", &nights);
	for (int n = 0; n < nights; n++) {
		field = vector<vector<int>>(100, vector<int>(100, 0));
		for (int i = 0; i < 2; i++) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for (int i = y1; i < y2; i++) {
				for (int j = x1; j < x2; j++) {
					field[i][j] += 1;
				}
			}
		}
		int ur = 0, wsr = 0, ssr = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				switch (field[i][j]) {
				case 0:
					ur++;
					break;
				case 1:
					wsr++;
					break;
				case 2:
					ssr++;
					break;
				}
			}
		}
		printf("Night %d: %d %d %d\n", n+1, ssr, wsr, ur);
	}
    return 0;
}
