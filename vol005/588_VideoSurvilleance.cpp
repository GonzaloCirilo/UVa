#include <stdio.h>//588
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, x, y, cont = 1;
	while (scanf("%d", &n) && n) {
		vector<pair<int, int>> pos;
		int minx = -99999, maxx = 99999, miny = -99999, maxy = 99999;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			pos.push_back({ x,y });
		}
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			int difx = pos[i].first - pos[j].first, dify = pos[i].second - pos[j].second;
			if (difx == 0) {
				if (dify < 0) {
					minx = max(minx, pos[i].first);
				}
				else {
					maxx = min(maxx, pos[i].first);
				}
			}
			else {
				if (difx < 0) {
					maxy = min(maxy, pos[i].second);	
				}
				else {
					miny = max(miny, pos[i].second);
				}
			}
		}
		printf("Floor #%d\n", cont);
		if (minx <= maxx && miny <= maxy)
			printf("Surveillance is possible.\n");
		else
			printf("Surveillance is impossible.\n");
		printf("\n");
		cont++;
	}
	return 0;
}