#include <stdio.h>
bool hasDiffDigits(int n){
    int taken [10] = {};
    while(n > 0){
        int digit = n % 10;
        if(!taken[digit])
            taken[digit] = 1;
        else
            return false;
        
        n /= 10;
    }
    return true;
}
int main(){
    int n, m;
    int arr[5001] = {};
    for(int i = 1; i < 5001; i++){
        arr[i] = arr[i - 1] + hasDiffDigits(i);
    }
    while(scanf("%d %d", &n, &m) != EOF){
        printf("%d\n", arr[m] - arr[n - 1]);
    }
}