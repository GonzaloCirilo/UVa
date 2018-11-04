#include <stdio.h>
#include <vector>
#include <set>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<vector<int>> map, mapG, visited;// visited acts like the closed list
ii s, d;
int r, c, nrb, ar, nb, ac, inf = -2;
double Manhattan(ii pos) {
	return abs(pos.first - d.first) + abs(pos.second - d.second);
}
bool checkMap(ii pos) {
	return (pos.second >= 0 && pos.second < c&&pos.first>= 0 && pos.first < r) && map[pos.first][pos.second] != inf;
}
int main() {
	vector<ii> moves = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	while (scanf("%d %d", &r, &c) && r && c) {
		set<iii> open;
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
		scanf("%d %d", &s.first, &s.second);
		scanf("%d %d", &d.first, &d.second);
		open.insert({ 0,{ s.first,s.second } });
		int newG, newF, newH;
		while (!open.empty()) {// f = G + h
			ii pos = (*open.begin()).second;
			visited[pos.first][pos.second] = true;
			if (pos == d) break;
			open.erase(open.begin());
			for (int i = 0; i < moves.size(); i++) {
				ii newPos = { pos.first + moves[i].first,pos.second + moves[i].second };
				if (checkMap(newPos)) {
					newG = mapG[pos.first][pos.second] + 1;
					newH = Manhattan(newPos);
					newF = newG + newH;
					if (!visited[newPos.first][newPos.second] && map[newPos.first][newPos.second] != inf && (map[newPos.first][newPos.second] > newF || map[newPos.first][newPos.second] == -1)) {
						open.insert({ newF,newPos });
						mapG[newPos.first][newPos.second] = newG;
						map[newPos.first][newPos.second] = newF;
					}
				}
			}
		}
		printf("%d\n", mapG[d.first][d.second]);
	}
	return 0;
}