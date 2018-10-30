#include <stdio.h>
#include <queue>
#include <functional>
#include <string.h>
#include <algorithm>
#include <ctype.h>
using namespace std;
typedef pair<int, string> ist;
bool compare(ist a, ist b) {
		string as = a.second, bs = b.second;
		transform(as.begin(), as.end(), as.begin(), ::tolower);
		transform(bs.begin(), bs.end(), bs.begin(), ::tolower);
		if (a.first == b.first)
			return as < bs;
		return a.first > b.first;

}
int main() {
	int n, counter = 1;
	char name[25], scores[100];
	while (scanf("%d\n", &n) != EOF) {
		printf("Case %d:\n", counter);
		vector<ist> pq;
		for (int i = 0; i < n; i++) {
			int score = 0;
			scanf("%[^;]%*c%[^\n]%*c", name, scores);
			for (int j = 0; j < 25; j++) {
				score += ((int)(scores[j * 2] == '1') + (int)(scores[j * 2] == '1' && scores[j * 2 + 1] == ';'));
			}
			score += scores[48] == '1';
			pq.push_back({ score,name });
		}
		sort(pq.begin(), pq.end(), compare);
		for (int i = 0; i < pq.size(); i++) {
			printf("%s %d\n", pq[i].second.c_str(), pq[i].first);
		}
		counter++;
	}
	return 0;
}