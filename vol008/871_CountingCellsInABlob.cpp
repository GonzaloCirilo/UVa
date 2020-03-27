#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int,int> ii;

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    int grid[27][27] = {}, dr[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    while (t--){
        int i = 0, j = 0; char token;
        while(true){
            token = getchar();
            if(token == '\n' || token == EOF) break;
            grid[i][0] = token - '0';
            j = 1;
            while(true){
                token = getchar();
                if(token == '\n' || token == EOF) break;
                grid[i][j++] = token - '0';
            }
            i++;
        }

        queue<ii> q;
        int ans = 0;
        for(int k = 0; k <= i; k++){
            for(int l = 0; l < j; l++){
                if(grid[k][l]){
                    int cont = 1;
                    q.push({k,l});
                    grid[k][l] = 0;
                    while(!q.empty()){
                        ii u = q.front(); q.pop();
                        for(int m = 0; m < 8; m++){
                            ii v = {u.first + dr[m], u.second + dc[m]};
                            if(v.first >= 0 && v.first <= i && v.second >= 0 && v.second < j && grid[v.first][v.second]){
                                cont++;
                                grid[v.first][v.second] = 0;
                                q.push(v);
                            }
                        }
                    }
                    if(cont > ans)
                        ans = cont;
                }
            }
        }
        printf("%d\n", ans);

        if(t!=0)
            printf("\n");
    }
    
    return 0;
}