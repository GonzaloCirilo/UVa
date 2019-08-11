#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    int a[3], x[2];
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &x[0], &x[1]) && a[0]){
        //printf("==%d %d %d %d %d\n", a[0], a[1], a[2], x[0], x[1]);
        int taken[53] = {};
        sort(a, a + 3);
        sort(x, x + 2);
        taken[a[0]] = 1;
        taken[a[1]] = 1;
        taken[a[2]] = 1;
        taken[x[0]] = 1;
        taken[x[1]] = 1;
        int l = 53;
        
        
        if(a[2] < x[0]){
            l = 1;
        }
        if(a[2] < x[1]){
            l = min(a[2] + 1, l);
        }
        if(a[1] < x[0]){
            l = min(a[1] + 1, l);
        }
        //printf("with: %d", l);
        if(l == 53){
            printf("-1\n");
        }else{
            bool found = false;
            for(int i = l; i < 53; i++){
                if(!taken[i]){
                    printf("%d\n", i);
                    found = true;
                    break;
                }
            }
            if(!found)
                printf("-1\n");
        }        
    }
    return 0;
}