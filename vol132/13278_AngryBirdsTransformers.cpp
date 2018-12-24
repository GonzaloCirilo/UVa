#include <stdio.h>
#include <vector>
using namespace std;
vector<int> starting, ending;
int main(){
	int n, x, y, sa=10001, ea=0;
	while(scanf("%d", &n) && n){
		starting = vector<int>(10001, 0);
		ending = vector<int>(10001,0);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			int dif = x - y > 0 ? x - y : 0, sum = x + y < 10001 ? x + y : 10000;
			sa = sa > dif ? dif : sa;
			starting[dif]++;
			ea = ea < sum ? sum : ea;
			ending[sum]++;
		}
		int ans = 0, sweep=0;
		for(int i = sa; i <= ea; i++){
			sweep += starting[i];
			ans = ans < sweep ? sweep : ans;
			sweep -= ending[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}