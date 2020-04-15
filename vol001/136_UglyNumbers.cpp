#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int ugly[1500], cand[3] = {2, 3, 5}, indx[3] = {0, 0, 0}, primes[3] = {2, 3, 5};
    ugly[0] = 1;
    for(int i = 1; i < 1500; i++){
        ugly[i] = *min_element(cand, cand + 3);

        for(int j = 0; j < 3; j++){
            if(ugly[i] == cand[j]){
                indx[j]++;
                cand[j] = ugly[indx[j]] * primes[j];
            }
        }
    }
    printf("The 1500'th ugly number is %d.\n", ugly[1499]);
    return 0;
}