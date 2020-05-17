#include <stdio.h>
#include <vector>

using namespace std;

int reverse(int n){
    int aux = 0;
    while(n > 0){
        aux *= 10;
        aux += n % 10;
        n /= 10;
    }
    return aux;
}

int main(){
    vector<int> prime = vector<int>(1000000, 1);

    for(int p = 2; p * p <= 1000001; p++){
        if(prime[p]){
            for(int i = p * p; i <= 1000001; i += p)
                prime[i] = 0;
        }
    }
    int n;
    while(scanf("%d", &n) != EOF){
        if(prime[n] && prime[reverse(n)] && n != reverse(n))
            printf("%d is emirp.\n", n);
        else if(prime[n])
            printf("%d is prime.\n", n);
        else 
            printf("%d is not prime.\n", n);
    }
    return 0;
}