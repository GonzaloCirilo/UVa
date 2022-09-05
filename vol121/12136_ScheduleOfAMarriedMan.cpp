#include <stdio.h>

int main () {

    int n, wst, wet, mst, met;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        printf("Case %d: ", i);
        int h1, h2, m1, m2;
        int arr[1441] = {};
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        //printf("%d:%d %d:%d\n", h1, m1, h2, m2);
        
        wst = m1 + h1 * 60, wet = m2 + h2 * 60;
        if (wet <= wst) wet += 1440;
        for(int j = wst; j <= wet; j++){
            arr[j % 1440]++;
        }
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        //printf("%d:%d %d:%d\n", h1, m1, h2, m2);
        
        mst = m1 + h1 * 60, met = m2 + h2 * 60;
        if(met <= mst) met += 1440;
        bool collide = false;
        for(int j = mst; j <= met; j++){
            if(arr[j % 1440]){
                collide = true;
                break;
            }
        }
        if(collide){
            printf("Mrs Meeting\n");
        }else {
            printf("Hits Meeting\n");
        }
    }
    return 0;
}