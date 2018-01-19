#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		int extension;
		scanf("%d", &extension);
		char car; vector<int> line = vector<int>(100, 0);
		int nscare = 0;
		for (int i = 0; i < extension; i++) {
			scanf(" %c", &car);
			if (car == '#') {
				line[i] = 1;
				continue;
			}
			if (car == '.'&&line[i] != 1) {
				line[i] = 1; line[i + 1] = 1; line[i + 2]=1;
				nscare++;
				continue;
			}
		}
		printf("Case %d: %d\n", c + 1, nscare);
	}
    return 0;
}
