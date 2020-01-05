#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int w, h, n, x1, y1, x2, y2;
    while(scanf("%d %d %d", &w, &h, &n) != EOF && w && h){
        int grid[501][501] = {};
        int ans = w * h;
        while(n--){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for(int i = min(x1, x2); i <= max(x1, x2); i++){
                for(int j = min(y1, y2); j <= max(y1, y2); j++){
                    if(!grid[i][j]){
                        grid[i][j] = 1;
                        ans--;
                    }
                }
            }
        }
        if(ans == 0)
            printf("There is no empty spots.\n");
        else if (ans == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", ans);
    }
}