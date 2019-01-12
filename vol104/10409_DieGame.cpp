#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n;
	char cmd[11];
	while (scanf("%d\n", &n) && n) {
		pair<int, int>top = { 1,6 }, north = { 2,5 }, west = { 3,4 };
		for (int i = 0; i < n; i++) {
			pair<int, int> aux;
			fgets(cmd, 12, stdin);
			switch (cmd[0]) {
			case 'n':
				aux = north;
				north = top;
				top = { aux.second,aux.first };
				break;
			case 's':
				aux = north;
				north = { top.second,top.first };
				top = aux;
				break;
			case 'e':
				aux = west;
				west = { top.second,top.first };
				top = aux; 
				break;
			case 'w':
				aux = west;
				west = top;
				top = { aux.second,aux.first };
				break;
			}
		}
		printf("%d\n", top.first);
	}
}