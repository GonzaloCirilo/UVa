#include <stdio.h>

long long modPow(long long b, long long p, long long m){
    if(m == 1)
        return 0;
    else{
        int ans = 1;
        b = b % m;
        while(p > 0){
            if(p % 2 == 1)
                ans = (ans * b) % m;
            p = p >> 1;
            b = (b * b) % m;
        }
        return ans;
    }
}

int main(){
    long long b, p, m;
    while(scanf("%lld\n%lld\n%lld", &b, &p, &m) != EOF){
        printf("%lld\n", modPow(b, p, m));
    }
    return 0;
}