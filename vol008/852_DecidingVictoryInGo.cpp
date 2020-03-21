#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    scanf("%d\n", &n);
    int grid[9][9] = {};
    while(n--){
        vector<ii> valid = vector<ii>();
        vector<ii> stones = vector<ii>();
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = getchar();
                if(c == '.') {valid.push_back({i,j}); grid[i][j] = 0;}
                else if(c == 'X') {stones.push_back({i,j}); grid[i][j] = 1;}
                else if(c == 'O') {stones.push_back({i,j}); grid[i][j] = 2;}
            }
            getchar();
        }

        queue<ii> q;

        int w = 0, b = 0;

        for(int i = 0; i < valid.size(); i++){
            ii s = valid[i];
            if(!grid[s.first][s.second]){
                int cont = 1;
                int color = 0; // 1 - black, 2 - white, 4 - invalid
                q.push(s);
                grid[s.first][s.second] = 3;
                while(!q.empty()){
                    ii n = q.front(); q.pop();
                    for(int j = -1; j < 2; j += 2){
                        if(n.first + j >= 0 && n.first + j < 9){
                            if(!grid[n.first + j][n.second]){
                                grid[n.first + j][n.second] = 3;
                                cont++;
                                q.push({n.first + j, n.second});
                            }else if(grid[n.first + j][n.second] != 3){
                                if(color == 0 || color == grid[n.first + j][n.second]){
                                    color = grid[n.first + j][n.second];
                                }else
                                    color = 4;
                            }
                        }

                        if(n.second + j >= 0 && n.second + j < 9){
                            if(!grid[n.first][n.second + j]){
                                grid[n.first][n.second + j] = 3;
                                cont++;
                                q.push({n.first, n.second + j});
                            }else if(grid[n.first][n.second + j] != 3){
                                if(color == 0 || color == grid[n.first][n.second + j]){
                                    color = grid[n.first][n.second + j];
                                }else
                                    color = 4;
                            }
                        }
                    }
                }     

                if(color == 1)   
                    b += cont;
                else if(color == 2)
                    w += cont;        
            }

        }

        for(int i = 0; i < stones.size(); i++){
            ii s = stones[i];
            if(grid[s.first][s.second] != 3){
                int cont = 1;
                q.push(s);
                int color = grid[s.first][s.second];
                grid[s.first][s.second] = 3;
                while(!q.empty()){
                    ii n = q.front(); q.pop();
                    for(int j = -1; j < 2; j += 2){
                        if(n.first + j >= 0 && n.first + j < 9){
                            if(grid[n.first + j][n.second] == color){
                                grid[n.first + j][n.second] = 3;
                                cont++;
                                q.push({n.first + j, n.second});
                            }
                        }

                        if(n.second + j >= 0 && n.second + j < 9){
                            if(grid[n.first][n.second + j] == color){
                                grid[n.first][n.second + j] = 3;
                                cont++;
                                q.push({n.first, n.second + j});
                            }
                        }
                    }
                }     
                if(color == 1)   
                    b += cont;
                else if(color == 2)
                    w += cont;        
            }

        }

        printf("Black %d White %d\n", b, w);
    }
    return 0;
}