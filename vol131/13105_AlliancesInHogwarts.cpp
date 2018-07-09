#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
vi pset;
int n, c, x, y, m;
void init(int n) {
	pset = vi(2*n, -1);
}
int findSet(int p) {
	if (pset[p] == -1)
		return p;
	return pset[p] = findSet(pset[p]);
}
bool isSameSet(int a, int b) {
	return findSet(a) == findSet(b);
}
void unionSet(int a, int b) {
	if (!isSameSet(a, b))
		pset[findSet(a)] = findSet(b);
}
bool areEnemies(int a, int b) {//new findSet in enemies
	return findSet(a) == findSet(b + n) || findSet(a + n) == findSet(b);
}
bool areFriends(int a, int b) {
	return findSet(a) == findSet(b) || findSet(a + n) == findSet(b + n);
}
int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		init(n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &c, &x, &y);
			switch (c) {
			case 1://setFriends
				if (areEnemies(x, y))
					printf("-1\n");
				else {
					unionSet(x, y);
					unionSet(x + n, y + n);
				}
				break;
			case 2://setEnemies
				if (areFriends(x, y))
					printf("-1\n");
				else {
					unionSet(x, y + n);
					unionSet(x + n, y);
				}
				break;
			case 3://areFriends
				printf("%d\n", areFriends(x, y));
				break;
			case 4://areEnemies
				printf("%d\n", areEnemies(x, y));
				break;
			}
		}
	}
	return 0;
}