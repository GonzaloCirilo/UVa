#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    scanf("%d\n", &n);
    int grid[31][81] ={};
    int dr[4] = {0, 0, 1, -1}, dc[4] = { 1, -1, 0, 0 };
    while(n--){
        int row = 0, col = 0, sr, sc;
        bool end = false;
        do{
            int auxC = 0;
            char c = getchar(), init = c;
            while(c != '\n' && c != EOF){
                if(c == '*'){
                    grid[row][auxC] = -1;
                    sr = row;
                    sc = auxC;
                }
                else if(c == ' ')
                    grid[row][auxC] = -3;
                else if(c == '_')
                    grid[row][auxC] = -4;
                else
                    grid[row][auxC] = (int)c;
                c = getchar();
                auxC++;
            }
            grid[row][auxC] = 0;
            col = max(col, auxC);
            row++;
            end = init == '_';
        } while(!end);
        
        queue<ii> q;
        q.push({ sr, sc });
        while(!q.empty()){
            ii actual = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                ii newPos = { actual.first + dr[i], actual.second + dc[i] };
                if(grid[newPos.first][newPos.second] == -3){
                    q.push(newPos);
                    grid[newPos.first][newPos.second] = -1;
                }
            }
        }

        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0)
                    break;
                else if(grid[i][j] == -1)
                    putchar('#');
                else if(grid[i][j] == -3)
                    putchar(' ');
                else if(grid[i][j] == -4)
                    putchar('_');
                else 
                    putchar((char)grid[i][j]);
                
            }
            putchar('\n');
        }


    }
    return 0;
}