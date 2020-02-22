#include <stdio.h>
#include <math.h>

long long countDivs(long long n) { 
    long long count = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                count++; 
            else 
                count += 2; 
        } 
    } 
    return count; 
} 

int main(){
    int t; 
    long long u, l;
    scanf("%d", &t);

    while(t--){
        scanf("%lld %lld", &u, &l);
        printf("Between %lld and %lld, ", u, l);

        long long max = 0, ind = 0;

        for(long long i = u; i <= l; i++){
            long long aux = countDivs(i);
            if(aux > max){
                max = aux;
                ind = i;
            }
        }

        printf("%lld has a maximum of %d divisors.\n", ind, max);
    }
    return 0;
}