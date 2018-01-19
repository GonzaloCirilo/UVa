#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>vvi;
vvi Manhattan;

int main()
{
	int sceneraios;
	scanf("%d", &sceneraios);
	for (int s = 0; s < sceneraios; s++) {
		int defusion;
		Manhattan = vvi(1025, vi(1025, 0));
		scanf("%d", &defusion);
		int rp;
		scanf("%d", &rp);
		for (int i = 0; i < rp; i++) {
			int x, y, p;
			scanf("%d %d %d", &x, &y, &p);
			for (int w = y - defusion; w <= y + defusion; w++) {
				for (int z = x - defusion; z <= x + defusion; z++) {
					if (w >= 0 && w < 1025 && z>=0 && z < 1025) {
						Manhattan[z][w] += p;
					}
				}
			}
		}
		int max = -1, sx, sy;
		for (int i = 0; i < 1025; i++) {
			for (int j = 0; j < 1025; j++) {
				if (max < Manhattan[i][j]) {
					max = Manhattan[i][j];
					sx = i; sy = j;
				}
			}
		}
		printf("%d %d %d\n", sx, sy, max);
	}
    return 0;
}
