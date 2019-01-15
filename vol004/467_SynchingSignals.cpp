#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	char tokens[35];
	int n, cont = 1;
	while (fgets(tokens, 35, stdin)) {
		vector<int> cycles;
		stringstream ss(tokens);
		while (ss >> n) {
			cycles.push_back(n*2);
		}
		int lowest = *min_element(cycles.begin(), cycles.end());
		
		while (lowest <= 3600) {
			bool green = true;
			for (auto it = cycles.begin(); it != cycles.end(); it++) {
				if (lowest % *it >= (*it / 2) - 5)//check if in the currennt time the ith signal is green
					green = false;
			}
			if (green)
				break;
			lowest++;
		}
		printf("Set %d ", cont);
		if (lowest > 3600)
			printf("is unable to synch after one hour.\n");
		else
			printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", lowest / 60, lowest % 60);
		cont++;
	}
	return 0;
}