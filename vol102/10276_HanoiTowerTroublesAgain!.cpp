#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
typedef vector<vector<int>> vvi;
bool isSquareNumber(int n) {
	int aux = sqrt(n);
	return aux*aux == n;
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int p;
		scanf("%d", &p);
		vvi HanoiT = vvi(p);
		int cont = 1;
		int ans = 0;
		while (true) {
			int aux = ans;
			for (int i = 0; i < p; i++) {
				if (HanoiT[i].size() == 0|| isSquareNumber(HanoiT[i].back() + cont)) {
					HanoiT[i].push_back(cont);
					cont++;
					ans++;
					break;
				}
			}
			if (ans == aux)break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
