#include <stdio.h>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;
typedef vector<bool>Vb;
int N, nt;
int tracks[20];
vector<int>res;
int total_lenght;
typedef vector<int>Vi;
typedef vector<Vi>Gi;
Gi graph;
void DFS(int node,int value,vector<int>v,int tt) {

	v.push_back(value-tt);
	if (total_lenght < value&& value <= N) {
		total_lenght = value;
		res = v;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		int adjacent = graph[node][i];
		if (value + tracks[adjacent] <= N) {
			tt = value;
			DFS(adjacent, value + tracks[adjacent],v,tt);
		}
	}
	v.pop_back();
}
int main()
{
	pair<int, Vi>r;
	while (scanf("%d %d", &N, &nt) == 2) {
		graph = Gi(nt);
		for (int i = 0; i < nt; i++) {
			scanf("%d", &tracks[i]);
			for (int j = 0 + i; j < nt; j++) {
				if (i != j) {
					graph[i].push_back(j);
				}
			}
		}
		int max = 0;
		for (int i = 0; i < nt; i++) {
			vector<int>v;
			res.clear();
			total_lenght = 0;
			DFS(i, tracks[i],v,0);
			if (max < total_lenght) {
				max = total_lenght;
				r = { total_lenght,res };
			}
		}
		for (int i = 0; i < r.second.size(); i++) {
			printf("%d ", r.second.at(i));
		}
		printf("sum:%d\n", r.first);

	}
    return 0;
}
