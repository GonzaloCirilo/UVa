#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int,int>ii;

int main(){
    char c;
    const char * formats[4] = {"%d", "%2d", "%3d", "%4d"};
    int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};

    while(true){
        char grid[300][300] = {};
        int visited[300][300] = {};
        int row = 0, col = 0;
        while(true){
            c = getchar();
            if(c == '%' || c == EOF) break;
            col = 0;
            grid[row][col++] = c;

            while(true){
                c = getchar();
                if(c == '\n' || c == EOF) break;
                if(c != ' '){
                    grid[row][col++] = c;
                }
                
            }
            row++;
        }
        int times = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j]){
                    char token = grid[i][j];
                    queue<ii> q;
                    q.push({i,j});
                    visited[i][j] = times;
                    while(!q.empty()){
                        ii u = q.front(); q.pop();
                        for(int k = 0; k < 8; k++){
                            ii v = {u.first+dr[k], u.second+dc[k]};
                            if(v.first >= 0 && v.first < row && v.second >= 0 && v.second < col){
                                if(!visited[v.first][v.second] && grid[v.first][v.second] == token){
                                    visited[v.first][v.second] = times;
                                    q.push(v);
                                }
                            }
                        }
                    }
                    times++;
                }
            }
        }

        int maxDigits[300] = {};

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                if(visited[j][i] > maxDigits[i]){
                    maxDigits[i] = visited[j][i];
                }
            }
            // get the digits
            maxDigits[i] = (int) log10((double) maxDigits[i]) + 1;
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j != 0) putchar(' ');
                printf(formats[maxDigits[j] - 1], visited[i][j]);
            }
            putchar('\n');
        }
        putchar('%');
        putchar('\n');
        if(c == EOF) break;
        else if(c == '%') getchar();
    }

    return 0;
}