#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int>ii;
ii moves[9] = { {1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{0,-1},{1,1},{-1,-1} };
int r, c;
bool validStar(ii star) {
	return star.first >= 0 && star.first < r && star.second >= 0 && star.second < c;
}
int main() {
	bool visited[103][103];
	char token[103][103];
	queue<ii> q;
	while (scanf("%d %d\n", &r, &c) && r && c){
		for (int i = 0; i < r; i++) {
			scanf("%s", &token[i]);
			for (int j = 0; j < c; j++) {
				visited[i][j] = token[i][j] == '.';
			}
		}
		int ans = 0, cont = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!visited[i][j]) {
					q.push({ i,j });
					visited[i][j] = true;
					cont = 1;
					while (!q.empty()){
						ii star = q.front(); q.pop();
						for (int k = 0; k < 9; k++) {
							ii newStar = { star.first + moves[k].first,star.second + moves[k].second };
							if (validStar(newStar) && !visited[newStar.first][newStar.second]) {
								q.push(newStar);
								visited[newStar.first][newStar.second] = true;
								cont++;
							}
						}
					}
					ans += cont == 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}