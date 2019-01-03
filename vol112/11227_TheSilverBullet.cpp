#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> dd; 
bool collinear(dd a, dd b, dd c) {
	return (((b.first - a.first)*(c.second - a.second)) - ((c.first - a.first)*(b.second - a.second))) / 2.0 == 0.0;
}
int main() {
	int t, n, x1, x2, y1, y2;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Data set #%d contains", i);
		scanf("%d", &n);
		set<dd> s;
		vector<dd> points;
		while (n--) {
			scanf("%d.%d %d.%d", &x1, &x2, &y1, &y2);
			if (s.insert({ x1 * 100 + x2,y1 * 100 + y2 }).second) {
				points.push_back({ x1 * 100 + x2,y1 * 100 + y2 });
			}
		}
		if (s.size() == 1) {
			printf(" a single gnu.\n");
			continue;
		}
		int ans = 2;
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				int cont = 2;
				for (int k = 0; k < points.size(); k++) {
					if (k != i && k != j && collinear(points[i], points[j], points[k])) {
						cont++;
					}
				}
				ans = ans < cont ? cont : ans;
			}
		}
		printf(" %d gnus, out of which a maximum of %d are aligned.\n", points.size(), ans);
	}
	return 0;
}