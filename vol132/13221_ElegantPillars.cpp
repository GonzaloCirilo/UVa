#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	//ans = n + sum(2k) 1<k<n
	long long p;
	while(scanf("%lld", &p)!=EOF) {
		long long ans = 0;
		if(p % 2 == 0){
			long long aux = p/2;
			ans =  aux * aux * 2 + p - 1;
		}else{
			long long aux = (p-1)/2;
			ans	= (aux*(aux+1)*2) + p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
