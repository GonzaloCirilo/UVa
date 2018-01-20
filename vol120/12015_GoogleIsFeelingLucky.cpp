#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <functional>
using namespace std;
int main() {
	int t, c, p; char curl[101];
	string url;
	vector<vector<string>> v;
	priority_queue<int, vector<int>, less<int>>pq;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		v = vector<vector<string>>(100);
		pq = priority_queue<int, vector<int>, less<int>>();
		c = 10;
		while (c) {
			scanf("%100s %d", &curl, &p);
			url = curl;
			pq.push(p - 1);
			v[p - 1].push_back(url);
			c--;
		}
		int a = pq.top();
		printf("Case #%d:\n", i + 1);
		for (int i = 0; i < v[a].size(); i++) {
			printf("%s\n", v[a][i].c_str());
		}
	}
	return 0;
}