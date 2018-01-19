#include <queue>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> si;
int main()
{
	int t, n, k, f; map<string, int>dict;
	vector<string>names;
	priority_queue<si, vector<si>, greater<si>>pq;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		for (int j = 0; j < n; j++) {
			char temp[101];
			scanf("%100s %d", temp, &f);
			string name = temp;
			dict[name] = f;
			names.push_back(name);
			pq.push({ f,j });
		}
		for (int j = 0; j < k; j++) {
			auto aux = pq.top(); pq.pop();
			pq.push({ aux.first + dict[names[aux.second]],aux.second });
			printf("%d %s\n", aux.first, names[aux.second].c_str());
		}
	}
	return 0;
}
