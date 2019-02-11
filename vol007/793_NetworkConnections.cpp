#include <stdio.h>
#include <vector>
using namespace std;
vector<int> pset;
void init(int n) {
	pset = vector<int>(n, -1);
}
int findset(int n) {
	if (pset[n] == -1)
		return n;
	return pset[n] = findset(pset[n]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionSet(int a, int b) {
	if (!isSameSet(a, b)) 
		pset[findset(a)] = findset(b);
}
int main() {
	int t, n, u, v, successful, unsuccessful;
	char cmd, tokens[25];
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		scanf("%d\n", &n);
		init(n);
		successful = 0, unsuccessful = 0;
		while (fgets(tokens, 25, stdin) && tokens[0] != '\n') {
			sscanf(tokens,"%c %d %d\n", &cmd, &u, &v);
			if ('c' == cmd)
				unionSet(u - 1, v - 1);
			else {
				bool aux = isSameSet(u - 1, v - 1);
				successful += (int)aux;
				unsuccessful += (int)!aux;
			}
		}
		printf("%d,%d\n", successful, unsuccessful);
	}
	return 0;
}