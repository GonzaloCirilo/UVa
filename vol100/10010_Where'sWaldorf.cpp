#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
ii moves[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
char grid[52][52], words[20][55];
int t, n, m;
bool validPos(ii pos) {
	return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m;
}
bool search(ii pos, int index) {
	if (tolower(grid[pos.first][pos.second]) != tolower(words[index][0]))
		return false;

	for (int dir = 0; dir < 8; dir++){
		int k, rd = pos.first + moves[dir].first, cd = pos.second + moves[dir].second, len = strlen(words[index]) - 1;
		for (k = 1; k < len; k++){
			if (!validPos({ rd,cd }) || tolower(grid[rd][cd]) != tolower(words[index][k]))
				break;

			rd += moves[dir].first, cd += moves[dir].second;
		}
		if (k == len)
			return true;
	}
	return false;
}
void solve(int index) {
	for (int j = 0; j < n; j++) {
		for (int l = 0; l < m; l++) {
			if (search({ j,l }, index)) {
				printf("%d %d\n", j + 1, l + 1);
				return;
			}
		}
	}
	return;
}
int main() {
	int k;
	scanf("%d", &t);
	while (t) {
		scanf("\n%d %d\n", &n, &m);
		for (int i = 0; i < n; i++) {
			fgets(grid[i], m+2, stdin);
		}
		scanf("%d\n", &k);
		for (int i = 0; i < k; i++) {
			fgets(words[i], 52, stdin);
			solve(i);
		}
		if(t != 1)
			printf("\n");
		t--;
	}
	return 0;
}