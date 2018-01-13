#include <stdio.h>
#include <set>
using namespace std;
int main() {
	set<int> s;
	int n, m, cd, size, ans;
	while (true) {
		ans = 0;
		size = -1;
		s.clear();
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n + m; i++) {
			scanf("%d", &cd);
			s.insert(cd);
			if (s.size() == size) {
				ans++;
			}
			size = s.size();
		}
		printf("%d\n", ans);
	}
	return 0;
}