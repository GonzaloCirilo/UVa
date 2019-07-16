#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n, m, c, q, cont = 1;
    while (scanf("%d %d %d", &n, &m, &c) && (n || m || c)){
        printf("Sequence %d\n", cont++);
        int toggle[22] = {}, consumption[22] = {};
        for(int i = 0; i < n; i++){
            scanf("%d", &consumption[i]);
        }
        int maxe = 0, actual = 0;
        bool blown = false;
        for(int i = 0; i < m; i++){
            scanf("%d", &q); q--;
            if(toggle[q]){
                actual -= consumption[q];
            }else{
                actual += consumption[q];
            }
            if(actual > c)
                blown = true;
            maxe = max(maxe, actual);
            toggle[q] = !toggle[q];
        }
        if(blown)
            printf("Fuse was blown.\n\n");
        else
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxe);

    }
    
    return 0;
}