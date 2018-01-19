#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int test;
	vector<int> v = vector<int>(100001);
	int rungs;
	scanf("%d", &test);
	for (int i = 0; i<test; i++) {
		scanf("%d", &rungs);
		int max = 0, extra = 0;
		for (int r = 0; r < rungs; r++) {
			scanf("%d", &v[r]);
			if (r == 0) {
				max = v[r];
				continue;
			}
			if(v[r] - v[r-1] > max){
				max = v[r] - v[r-1];
			}
		}
		int aux = max;
		for(int r = 0; r < rungs; r++){
			if(v[r] - v[r-1] == max){
				max--;
			}else{
				if(v[r] - v[r-1] > max){
					extra = 1;
					break;
				}
			}
		}
		printf("Case %d: %d\n", i + 1, aux + extra);
	}
 	return 0;
}