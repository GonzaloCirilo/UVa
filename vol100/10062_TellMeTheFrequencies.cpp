#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
struct MyOperator
{
	bool operator() (ii const &a, ii const &b) {
		return a.first < b.first || (!(b.first < a.first) && a.second > b.second);
	}
} op;
int main() {
	char rune[1001]; bool first = true;
	vector<int> times = vector<int>(128, 0);
	while (gets(rune)) {
		first == true ? first = false : printf("\n");
		times = vector<int>(129, 0);
		int size = strlen(rune);
		for (int i = 0; i < size; i++) {
			times[(int)rune[i]] += 1;
		}
		vector<ii>list;
		for (int i = 32; i < times.size(); i++) {
			if (times[i] > 0)
				list.push_back({ times[i], i });
		}
		sort(list.begin(), list.end(), op);
		for (int i = 0; i < list.size(); i++) {
			printf("%d %d\n", list[i].second, list[i].first);
		}

	}
	return 0;
}