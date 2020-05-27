#include <stdio.h>
#include <map>
using namespace std;
int n, m, s;

bool validCell(int row, int col){
    return row >= 0 && row < n && col >= 0 && col < m;
}


int main(){
    char grid[103][103] = {};
    int moves[4][2]{ {0,-1}, {-1,0}, {0,1}, {1,0} };
    map<char, int> o;
    o.insert({'O', 0});
    o.insert({'N', 1});
    o.insert({'L', 2});
    o.insert({'S', 3});
    while(scanf("%d %d %d\n", &n, &m, &s) != EOF && (n || m || s)){

        int sr, sc, orientation;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c = getchar();

                switch (c) {
                case '.':
                    grid[i][j] = c;
                    break;
                case '*':
                    grid[i][j] = c;
                    break;
                case '#':
                    grid[i][j] = c;
                    break;
                default:   
                    grid[i][j] = '.'; 
                    sr = i, sc = j, orientation = o[c];
                    break;
                }
                //printf("%c", grid[i][j]);
            }
            //putchar('\n');
            getchar();
        }
        int ans = 0;
        //printf("====%d r: %d, c: %d\n", orientation, sr, sc);
        for(int i = 0; i < s; i++){
            char op = getchar();
            if(op == 'D'){
                orientation = (orientation + 1 + 4) % 4;
            }else if(op == 'E'){
                orientation = (orientation - 1 + 4) % 4;
            }else if(op == 'F'){
                int dr = moves[orientation][0] + sr, dc = moves[orientation][1] + sc;
                if(validCell(dr, dc) && grid[dr][dc] != '#'){
                    if(grid[dr][dc] == '*'){
                        ans++;
                        grid[dr][dc] = '.';
                    }
                    sr = dr, sc = dc;
                }
            }
            //printf("====%d r: %d, c: %d\n", orientation, sr, sc);

        }
        printf("%d\n", ans);
    }
    return 0;
}