#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>
#include <algorithm>
#include <map>
double PI = 3.14159265;
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<vector<int>>maps,mapG,visited;
vector<vector<ii>>movedoors;
const int inf = 100000;
ii start, ending;
int n, m;
int Manhattan(int x, int y) {
	return (abs(x - ending.first) + abs(y - ending.second));
}
bool checkMap(int x, int y, int dx, int dy) {
	return (x >= 0 && x < m && y >= 0 && y < n) && maps[y][x] != inf && (movedoors[y][x].first==-1 || (dx==(int)cos(movedoors[y][x].first*PI/180)&& -dy==(int)sin(movedoors[y][x].first * PI / 180)));
}
int main()
{
	vector<int>costD;
	vector<ii>closed, moves = { {1,0},{0,1},{-1,0},{0,-1} };
	map<char, int>movdoor;
	map<pair<int, int>, int>kdoor;
	movdoor['W'] = 0; movdoor['N'] = 270; movdoor['S'] = 90; movdoor['E'] = 180;
	int t, k;
	scanf("%d", &t);
	while (t>0) {
		priority_queue<iii, vector<iii>, greater<iii>>open;
		closed.clear();
		maps.clear();
		costD.clear();
		scanf("%d %d", &n, &m);
		mapG = vector<vector<int>>(n, vector<int>(m, 0));
		visited = vector<vector<int>>(n, vector<int>(m, 0));
		movedoors = vector<vector<ii>>(n, vector<ii>(m, { -1,-1 }));
		int cont = 0;
		char token;
		for (int i = 0; i < n; i++) {
			vector<int>aux;
			for (int j = 0; j < m; j++) {
				scanf("\n%c", &token);
				switch (token)
				{
				case '.':
					aux.push_back(-1);
					break;
				case '#':
					aux.push_back(inf);
					break;
				default:	
					aux.push_back(-1);
					movedoors[i][j] = { movdoor[token],cont };
					cont++;
					break;
				}
			}
			maps.push_back(aux);
		}
		start = { 0,n-1 }, ending = { m-1,0 };
		for (int i = 0; i < cont; i++) {
			scanf("%d", &k);
			costD.push_back(k);
		}
		/*Astar algorithm*/
		open.push({ Manhattan(start.first,start.second),{ start.first,start.second } });
		while (!open.empty()) {
			auto aux = open.top(); open.pop();
			if (aux.second.first == ending.first&&aux.second.second == ending.second) { break; }
			for (int j = 0; j < moves.size(); j++) {
					int newx = aux.second.first + moves[j].first, newy = aux.second.second + moves[j].second;
					if (checkMap(newx, newy, moves[j].first, moves[j].second)) {
						int G = mapG[aux.second.second][aux.second.first]+1;
						int et = 0;
						if (movedoors[aux.second.second][aux.second.first].first != -1) {
							int x = cos((movedoors[aux.second.second][aux.second.first].first+180)*PI / 180), y = sin(movedoors[aux.second.second][aux.second.first].first * PI / 180);
							int difx = abs(x - moves[j].first), dify = abs(y - moves[j].second);
							if (abs(difx - dify) == 0 && difx == 1) {
								et += (costD[movedoors[aux.second.second][aux.second.first].second]);
							}
							else if (abs(difx - dify) == 2) {
								et += (costD[movedoors[aux.second.second][aux.second.first].second] * 2);
							}
						}
						int F = G + Manhattan(newx, newy);
						if ((maps[newy][newx] == -1 || maps[newy][newx] > F+et) && !visited[newy][newx]) {
							maps[newy][newx] = F/*-Manhattan(newx, newy)*/+et;
							mapG[newy][newx] = G+et;
							open.push({ maps[newy][newx],{ newx,newy } });
						}
					}
			}
			visited[aux.second.second][aux.second.first]=1;
		}
		if (start == ending)
			printf("0\n");
		else
			mapG[0][m - 1]!=0?printf("%d\n",mapG[0][m-1]):printf("Poor Kianoosh\n");
		t--;
	}
	return 0;
}