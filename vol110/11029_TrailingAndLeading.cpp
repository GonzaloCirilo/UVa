#include <stdio.h>
#include <math.h>

double binLog10(int a, int b) {
    double aux = log10(a);
    double ans = 0;
    while(b){
        if(b % 2 == 1){
            ans = ans + aux;
        }
        aux = aux + aux;
        b /= 2;
    }
    return ans;
}

int main(){
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        int ans = 1, lans = 0;
        double f = binLog10(n, k);
        f = f - (int)f;
        lans = pow(10, f) * 100;
        while(k){
            if(k % 2 == 1){
                ans = ((ans % 1000) * (n % 1000)) % 1000;
            }
            n = ((n % 1000) * (n % 1000)) % 1000;

            k /= 2;
        }
        printf("%d...%03d\n", lans, ans);
    }
    return 0;
}