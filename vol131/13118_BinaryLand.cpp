#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
struct Cell {
	vvi map;
};
int r, c, inf = -9999;
bool validCell(ii pos) {
	return pos.first >= 0 && pos.first < r && pos.second >= 0 && pos.second < c;
}
int main() {
	ii malonMoves[4] = { {1,0},{-1,0},{0,1},{0,-1} };
	ii gurinMoves[4] = { {1,0},{-1,0},{0,-1},{0,1} };
	char token[43];
	ii loveCell, gurinCell, malonCell;
	while (scanf("%d %d", &r, &c) != EOF) {
		vector<vector<Cell>> cells;
		vvi grid;
		scanf("%d %d %d %d %d %d %d", &loveCell.first, &loveCell.second, &gurinCell.first, &gurinCell.second, &malonCell.first, &malonCell.second);
		loveCell = { loveCell.first - 1,loveCell.second - 1 };
		gurinCell = { gurinCell.first - 1,gurinCell.second - 1 };
		malonCell = { malonCell.first - 1,malonCell.second - 1 };
		for (int i = 0; i < r; i++) {
			scanf("%s", &token);
			grid.push_back(vector<int>());
			for (int j = 0; j < c; j++) {
				grid[i].push_back(token[j] == '#' ? inf : 0);
			}
		}
		for (int i = 0; i < r; i++) {
			cells.push_back(vector<Cell>());
			for (int j = 0; j < c; j++) {
				Cell c;
				c.map = grid;
				cells[i].push_back(c);
			}
		}
		//bfs
		queue<ii> q;
		q.push(gurinCell);
		q.push(malonCell);
		while (!q.empty()) {
			ii gcell = q.front(); q.pop();
			ii mcell = q.front(); q.pop();
			if (loveCell == gcell && loveCell == mcell)break;
			for (int i = 0; i < 4; i++) {
				ii newGCell = { gcell.first + gurinMoves[i].first,gcell.second + gurinMoves[i].second };
				ii newMCell = { mcell.first + malonMoves[i].first,mcell.second + malonMoves[i].second };
				//check bounds and re adjust if necesary
				if (!validCell(newGCell))
					newGCell = gcell;
				if (!validCell(newMCell))
					newMCell = mcell;
				ii maux = newMCell, gaux = newGCell;// check if is an empty cell for each pinguin
				if (cells[newMCell.first][newMCell.second].map[newGCell.first][newGCell.second] == inf) {
						gaux = gcell;
				}
				if (cells[newGCell.first][newGCell.second].map[newMCell.first][newMCell.second] == inf) {
						maux = mcell;
				}//final check if its already visited
				if (cells[gaux.first][gaux.second].map[maux.first][maux.second] == 0 && (gaux != gcell || maux!= mcell) && (gaux != gurinCell || maux != malonCell)) {
						cells[gaux.first][gaux.second].map[maux.first][maux.second] = cells[gcell.first][gcell.second].map[mcell.first][mcell.second] + 1;
						q.push(gaux);
						q.push(maux);
				}	
			}
		}
		int ans = cells[loveCell.first][loveCell.second].map[loveCell.first][loveCell.second];
		if (ans != 0 || (loveCell == gurinCell && loveCell == malonCell))
			printf("%d\n",ans);
		else
			printf("NO LOVE\n");
	}
	return 0;
}