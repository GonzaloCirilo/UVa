#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int g;
	char c[15];
	vector<int> lows = vector<int>(), highs = vector<int>();
	while (scanf("%d\n", &g) && g) {
		fgets(c, 15, stdin);
		if (c[0] == 'r') {
			// print and reset
			bool honest = true;
			for (int i = 0; i < highs.size(); i++) {
				if (g >= highs[i]) {
					honest = false;
				}
			}
			for (int i = 0; i < lows.size(); i++) {
				if (g <= lows[i]) {
					honest = false;
				}
			}

			if (honest) {
				printf("Stan may be honest\n");
			}
			else {
				printf("Stan is dishonest\n");
			}

			highs.clear();
			lows.clear();
			continue;
		}
		if (c[4] == 'h') {
			highs.push_back(g);
		}
		else {
			lows.push_back(g);
		}
	}

	return 0;
}