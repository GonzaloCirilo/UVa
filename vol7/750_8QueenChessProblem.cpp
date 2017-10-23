#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int sol;
int r, c;
void print(vector<vector<int>>v) {
	printf("%2d      ", sol);
	for (int s = 0; s < v.size(); s++) {
		if (s == v.size() - 1) {
			printf("%d\n", v[s][1]);
			continue;
		}
		printf("%d ", v[s][1]);
	}
	sol++;
}
bool checkpos(std::vector<std::vector<int>> &v, int s, int x, int y)
{
	return v[s].at(0) == x || v[s].at(1) == y || abs(v[s].at(0) - x) == abs(v[s].at(1) - y);
}
bool validate(int x, int y, vector<vector<int>>v) {
	if (v.empty()) {
		return true;
	}
	else {
		bool aux;
		for (int s = 0; s < v.size(); s++) {
			if (v[s].size() > 0) {
				if (checkpos(v, s, x, y)) {
					aux = false;
					break;
				}
				else {
					aux = true;
				}
			}
		}
		return aux;
	}
}
void backtrack(vector<vector<int>>v, int n) {
	if (n == 9) {
		print(v);
	}
	else {
		if (n == c) {
			backtrack(v, n + 1);
		}
		else {
			for (int i = 1; i < 9; i++) {
				if (validate(n, i, v)) {
					vector<vector<int>>aux = v;
					v[n-1]={ n,i };
					backtrack(v, n + 1);
					v = aux;
				}
			}
		}
	}
}
int main()
{
	vector<vector<int>> positions;
	int cases;
	scanf("\n%d", &cases);
	for (int ca = 0; ca < cases; ca++) {
		positions= vector<vector<int>>(8);
		sol = 1;
		scanf("%d %d", &r, &c); int cp = c - 1;
		positions[cp]={c,r};
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		backtrack(positions, 1);
		if (ca != cases - 1)
			printf("\n");
	}
	return 0;
}

