#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
typedef vector<int>vi;
typedef vector<vector<int> >G;
int main() {
	int n, m, count = 1;
	vi in; vector<string> bv;
	char b1[51], b2[51];
	G graph;
	string sb1, sb2;
	map<string, int>beverages;
	priority_queue<int, vector<int>, greater<int>>q;
	while (scanf("%d", &n) != EOF) {
		beverages.clear();
		bv.clear();
		in = vi(n, 0);
		graph = G(n);
		for (int i = 0; i < n; i++) {
			scanf("%50s", &b1);
			sb1 = string(b1);
			beverages[sb1] = i;
			bv.push_back(sb1);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%50s %50s", &b1, &b2);
			sb1 = string(b1), sb2 = string(b2);
			graph[beverages[sb1]].push_back(beverages[sb2]);
			in[beverages[sb2]]++;
		}
		for (int i = 0; i < n; i++) {
			if (in[i] == 0)
				q.push(i);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", count);
		while (!q.empty()) {
			int node = q.top(); q.pop();
			for (int i = 0; i < graph[node].size(); i++) {
				int ad = graph[node][i];
				in[ad]--;
				if (in[ad] == 0)
					q.push(ad);
			}
			cout << " " << bv[node];
		}
		cout<<"." << endl << endl; count++;
	}
	return 0;
}
