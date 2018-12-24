#include <stdio.h>
#include <set>
using namespace std;
bool check(set<int> s) {
	auto it = s.begin();
	it++;
	for (; it != s.end(); it++) {
		if (*it - *prev(it) > 200) {
			printf("IMPOSSIBLE\n");
			return false;
		}
	}
	return true;
}
int main() {
	int n, d;
	set<int> s;
	while (scanf("%d", &n) && n) {
		s.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &d);
			s.insert(d);
		}
		s.insert((1422 - *prev(s.end())) * 2 + *prev(s.end()));
		if(check(s))
			printf("POSSIBLE\n");
	}
	return 0;
}