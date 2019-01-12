#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int t, n, l, d;
	map<string, int> sparrowList;
	char tokens[21];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d\n", &n);
		while (n--) {
			scanf("%s %d\n", &tokens, &l);
			sparrowList.insert({ string(tokens),l });
		}
		scanf("%d\n%s\n", &d, &tokens);
		printf("Case %d: ", i + 1);
		if (sparrowList.find(string(tokens)) != sparrowList.end()) {
			if (sparrowList[string(tokens)] <= d)
				printf("Yesss\n");
			else if(sparrowList[string(tokens)] <= d + 5)
				printf("Late\n");
			else
				printf("Do your own homework!\n");
		}
		else {
			printf("Do your own homework!\n");
		}
		sparrowList.clear();
	}
	return 0;
}