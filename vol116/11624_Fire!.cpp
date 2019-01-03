#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
ii moves[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int t, r, c, grid[1003][1003];
struct Node {
	int r, c, fire, depth;
};
bool validCell(int _r, int _c) {
	return _r >= 0 && _r < r && _c >= 0 && _c < c;
}
int main() {
	char token[1003];
	scanf("%d", &t);
	while (t) {
		scanf("%d %d\n", &r, &c);
		Node s, aux;
		queue<Node> q;
		for (int i = 0; i < r; i++) {
			fgets(token, 1003, stdin);
			for (int j = 0; j < c; j++) {
				grid[i][j] = token[j] != '.' && token[j] != 'J';
				if (token[j] == 'J') {
					s.r = i, s.c = j, s.fire = 0, s.depth = 1;
				}
				if (token[j] == 'F') {
					aux.r = i, aux.c = j, aux.fire = 1, aux.depth = 1;
					q.push(aux);
				}
			}
		}
		q.push(s);
		int ans = -1;
		bool finished = false;
		while (!q.empty() && !finished) {
			auto n = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int dr = n.r + moves[i].first, dc = n.c + moves[i].second;
				if (!validCell(dr, dc) && !n.fire) {
					finished = true;
					ans = n.depth;
				}
				if (validCell(dr, dc) && !grid[dr][dc]) {
					grid[dr][dc] = 1;
					aux.r = dr, aux.c = dc, aux.fire = n.fire, aux.depth = n.depth + 1;
					q.push(aux);
				}
			}
		}
		if (finished)
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
		t--;
	}
	return 0;
}