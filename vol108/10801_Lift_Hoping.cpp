#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii>iii;//{dist,{elev,floor}}
int main()
{
	int costEleveators[5];//Tn
	vector<vector<int>>stopsTime;
	vector<vector<int>>elevatorStops;
	vector<vector<int>>elevatorFloor;
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		priority_queue<iii, vector<iii>, greater<iii>>pq;
		stopsTime = vector<vector<int>>(5, vector<int>(100, 99999));
		elevatorStops = vector<vector<int>>(5);
		elevatorFloor = vector<vector<int>>(100);
		for (int i = 0; i < n; i++) {
			scanf("%d", &costEleveators[i]);
		}

		for (int i = 0; i < n; i++) {
			do {
				int x;
				scanf("%d", &x);
				elevatorStops[i].push_back(x);
				elevatorFloor[x].push_back(i);
			} while (getchar() != 10);
		}

		for (int i = 0; i < n; i++) {//djkstra for every elevator stopping at floor 0
			if (elevatorStops[i][0] != 0)continue;
			stopsTime[i][0] = 0;
			pq.push({ 0,{i,0} });
			while (!pq.empty()) {
				auto aux = pq.top(); pq.pop();
				int dist = aux.first, elev = aux.second.first, floor = aux.second.second;
				if (stopsTime[elev][floor] >= dist) {
					//Evaluating adyacent floors
					for (int j = 0; j < elevatorStops[elev].size(); j++) {
						int nextfloor = elevatorStops[elev][j];
						if (nextfloor == floor)continue;
						int tempo = abs(floor - nextfloor)*costEleveators[elev];
						if (stopsTime[elev][nextfloor] == 99999 || tempo + stopsTime[elev][floor] < stopsTime[elev][nextfloor]) {
							stopsTime[elev][nextfloor] = tempo + stopsTime[elev][floor];
							pq.push({ stopsTime[elev][nextfloor],{elev,nextfloor} });
						}
					}
					//Evaluating adjacent elevators
					for (int j = 0; j < elevatorFloor[floor].size(); j++) {
						int nextelev = elevatorFloor[floor][j];
						if (nextelev == elev ||floor == 0)continue;
						int tempo = floor == 0 ? 0 : 60;
						if (stopsTime[nextelev][floor] == 99999 || stopsTime[elev][floor] + tempo < stopsTime[nextelev][floor]) {
							stopsTime[nextelev][floor] = stopsTime[elev][floor] + tempo;
							pq.push({ stopsTime[nextelev][floor],{nextelev,floor} });
						}
					}

				}
			}
		}
		int min = 99999;
		for (int i = 0; i < n; i++) {
			if (stopsTime[i][k] < min) {
				min = stopsTime[i][k];
			}
		}
		if (min == 99999)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", min);
	}
	
	return 0;
}
