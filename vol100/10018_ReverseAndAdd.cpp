#include <iostream>
using namespace std;

long long reverse(long long x){
	long long aux = x, r = 0;
	while(aux > 0){
		r *= 10;
		r += aux % 10;
		aux /= 10;
	}
	return r;
}

bool isNotPalindrome(long long x){
	return reverse(x) != x;	
}

int main(){
	long long n, p;
	scanf("%lld", &n);
	while(n--){
		scanf("%lld", &p); int ans = 1;
		p += reverse(p);
		while(isNotPalindrome(p)){
			p += reverse(p);
			ans++;
		}
		printf("%d %lld\n", ans, p);
	}
}