#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
int main() {
	//freopen("out.txt", "w", stdout);
	int c, s;
	double a, ac, im;
	vector<ii> mass = vector<ii>(10);
	vector<iii> cell = vector<iii>(5);
	int ca = 1;
	while (scanf("%d %d", &c, &s) != EOF) {
		a = 0.0; ac = 0.0; im = 0.0;
		for (int i = 0; i < s; i++) {
			scanf("%d", &mass[i].first);
			a += mass[i].first;
			mass[i].second = i;
		}
		a /= c;
		for (int i = 0; i < 2 * c - s; i++) {
			mass[i + s] = { 0, 99999 };
		}
		sort(mass.begin(), mass.begin() + (2 * c));
		for (int i = 0; i < c; i++) {
			cell[i] = { min(mass[i].second,mass[2 * c - 1 - i].second),{ mass[i].first,mass[2 * c - 1 - i].first } };
			if (mass[i].second > mass[2 * c - 1 - i].second) {
				int aux = cell[i].second.first;
				cell[i].second.first = cell[i].second.second;
				cell[i].second.second = aux;
			}
		}
		sort(cell.begin(), cell.begin() + c, [](iii &left, iii &right) {
			return left.first < right.first;
		});
		printf("Set #%d\n", ca);
		for (int i = 0; i < c; i++) {
			printf(" %d:", i);
			if (cell[i].second.first != 0)
				printf(" %d", cell[i].second.first);
			if (cell[i].second.second != 0)
				printf(" %d", cell[i].second.second);
			ac = cell[i].second.first + cell[i].second.second;
			im += abs(a - ac);
			printf("\n");
		}
		printf("IMBALANCE = %.5f\n\n", im);
		ca++;
	}
	return 0;
}
