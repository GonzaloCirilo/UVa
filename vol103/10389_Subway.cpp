#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
#include <functional>
#include <iostream>
#include <sstream>
using namespace std;
typedef pair<int, int>ii;
typedef vector<ii> vii;
typedef pair<double, int> di;
typedef	vector<di>vdi;
typedef vector<vdi> G;
double calTime(ii posu, ii posv, double speed) {
	return sqrt(pow(posu.first - posv.first, 2) + pow(posu.second - posv.second, 2)) / (speed * 1000. / 60.);
}
int main() {
	vii coords;
	vector<int> subline;
	string l;
	int tc, sx, sy, tx, ty;
	G graph;
	vector<double> times;
	scanf("%d", &tc);
	while (tc) {
		int n = 2; coords.clear(); subline.clear();
		scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
		subline.push_back(-2); subline.push_back(-1);
		coords.push_back({ sx,sy }); coords.push_back({ tx,ty });
		cin.ignore();
		int sub = 0;
		while (getline(cin, l) && l != "") {
			stringstream ss;
			ss << l;
			while (ss >> sx >> sy) {
				if (sx == -1 && sy == -1)break;
				n++;
				coords.push_back({ sx,sy });
				subline.push_back(sub);
			}
			sub++;
		}
		graph = G(n);
		//Creating graph
		for (int i = 0; i < coords.size(); i++) {
			for (int j = i + 1; j < coords.size(); j++) {
				double speed = 10;
				if (subline[i] == subline[j] && abs(i - j) == 1) speed = 40;
				double t = calTime(coords[i], coords[j], speed);
				graph[i].push_back({ t,j });
				graph[j].push_back({ t,i });
			}
		}
		priority_queue<di, vector<di>, greater<di> > pq;
		times = vector<double>(n);
		pq.push({ 0,0 });
		times = vector<double>(n, -1);
		times[0] = 0;
		while (!pq.empty()) {
			int node = pq.top().second;
			double tnode = pq.top().first;
			if (times[node] >= tnode) {
				for (int i = 0; i < graph[node].size(); i++) {
					int ad = graph[node][i].second;
					double tad = graph[node][i].first;
					double newtime = tnode + tad;
					if (times[ad] == -1 || times[ad] > newtime) {
						times[ad] = newtime;
						pq.push({ newtime,ad });
					}
				}
			}
			pq.pop();
		}
		printf("%0.f\n", round(times[1]));
		tc--;
		if (tc)
			printf("\n");
	}
	return 0;
}
