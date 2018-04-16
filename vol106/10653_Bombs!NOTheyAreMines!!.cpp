#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>
#include <algorithm>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<vector<int>> map, mapG, visited;
const int inf = -2;
ii s, d, dif1, dif2;
int r, c, nrb, ar, nb, ac;
int Manhattan(ii pos) {
	dif2 = { pos.first - d.first,pos.second - d.second };
	return (abs(pos.first - d.first) + abs(pos.second - d.second) + abs(dif1.first*dif2.second-dif1.second*dif2.first));
}
bool checkMap(int x, int y) {
	return (x >= 0 && x < c&&y >= 0 && y < r) && map[y][x] != inf;
}
int main() {
	vector<ii> moves = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	while (scanf("%d %d", &r, &c) && r && c) {
		priority_queue<iii, vector<iii>, greater<iii>>open;
		map = vector<vector<int>>(r, vector<int>(c, -1));
		mapG = vector<vector<int>>(r, vector<int>(c, 0));
		visited = vector<vector<int>>(r, vector<int>(c, 0));
		scanf("%d", &nrb);
		while (nrb) {
			scanf("%d %d", &ar, &nb);
			for (int i = 0; i < nb; i++) {
				scanf("%d", &ac);
				map[ar][ac] = inf;
			}
			nrb--;
		}
		scanf("%d %d", &s.second, &s.first);
		scanf("%d %d", &d.second, &d.first);
		dif1 = { s.first - d.first,s.second - d.second };
		//A star
		open.push({ Manhattan(s),{ s.first,s.second } });
		int cont = 0;
		while (!open.empty()) {
			ii pos = open.top().second; int time = open.top().first; open.pop();
			if (pos.first == d.first && pos.second == d.second)break;
			for (int i = 0; i < moves.size(); i++) {
				int newx = pos.first + moves[i].first, newy = pos.second + moves[i].second;
				if (checkMap(newx, newy)) {
					int G = mapG[pos.second][pos.first] + 1;
					int h = G + Manhattan({ newx,newy });
					if ((map[newy][newx] == -1 || map[newy][newx] > h) && !visited[newy][newx]) {
						map[newy][newx] = h - Manhattan({ newx,newy });
						mapG[newy][newx] = G;
						open.push({ map[newy][newx] ,{ newx,newy } });
					}
				}
			}
			visited[pos.second][pos.first] = 1;
		}
		printf("%d\n", mapG[d.second][d.first]);
	}
	return 0;
}