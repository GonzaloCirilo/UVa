#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> ist;
bool compare(ist a, ist b) {
	string as = a.second, bs = b.second;
	transform(as.begin(), as.end(), as.begin(), ::tolower);
	transform(bs.begin(), bs.end(), bs.begin(), ::tolower);
	if (a.first == b.first)
		return as < bs;
	return a.first < b.first;

}
int main() {
	int n, m, s, ms;
	char name[150];
	while (scanf("%d", &n) == 1) {
		vector<ist> ranking = vector<ist>();
		for (int i = 0; i < n; i++) {
			scanf("%s : %d min %d sec %d ms", &name, &m, &s, &ms);
			ranking.push_back({ m * 60000 +  s * 1000 + ms,string(name) });
		}
		sort(ranking.begin(), ranking.end(), compare);
		for (int i = 0; i < n; i+= 2) {
			printf("Row %d\n", i/2 + 1);
			printf("%s\n", ranking[i].second.c_str());
			if (i + 1 < n)
				printf("%s\n", ranking[i + 1].second.c_str());
		}
		printf("\n");
	}
	return 0;
}