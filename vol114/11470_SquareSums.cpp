#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n, x, c = 1;
    while(scanf("%d", &n) && n){
        int arr[7] = {};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &x);
                // all posiible options
                int poss[4] = { i, j, n - i - 1, n - j - 1};
                arr[*min_element(poss, poss + 4)] += x;
            }
        }
        printf("Case %d:", c++);
        for(int i = 0; i < (n + 1) / 2; i++){
            printf(" %d", arr[i]);
        }
        printf("\n");

    }
    return 0;
}