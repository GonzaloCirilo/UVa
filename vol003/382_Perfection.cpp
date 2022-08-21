#include <iostream>
#include <vector>
#include <set>
using namespace std;

int getSumOfFactors(int n) {
    if (n == 1) return 0;
    set<int> factors = {1};
    for(int i = 2; i * i < n; i++){
        if(n%i == 0){
            factors.insert(i);
            if(i != n/i){
                factors.insert(n/i);
            }
        }
    }

    int sum = 0;
    for(auto it = factors.begin(); it != factors.end(); it++){
        sum += *it;
    }
    return sum;
}

int main(){
    int n;
    printf("PERFECTION OUTPUT\n");
    while(true){
        cin >> n;
        if(n == 0) break;
        printf("%5d  ", n);
        int result = getSumOfFactors(n);
        if(result < n){
            printf("DEFICIENT\n");
        }else if(result == n) {
            printf("PERFECT\n");
        }else if(result > n) {
            printf("ABUNDANT\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}