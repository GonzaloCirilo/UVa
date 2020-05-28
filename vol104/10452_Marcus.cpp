#include <stdio.h>
#include <string>
using namespace std;
int t, n, m;
bool isValid(int row, int col){
    return row >= 0 && row < n && col >= 0 && col < m;
}

int main(){
    char grid[9][9] = {}, word[7] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
    scanf("%d\n", &t);
    string dir[3] = {"forth", "left", "right"};
    int moves[3][2] = { {-1, 0}, {0, -1}, {0, 1} };
    while(t--){
        scanf("%d %d\n", &n, &m);
        int sr, sc;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c = getchar();
                grid[i][j] = c;
                if(c == '@'){
                    sr = i, sc = j;
                }
            }
            getchar();
        }

        int cont = 0;
        while(cont < 7){
            
            for(int i = 0; i < 3; i++){
                int dr = sr + moves[i][0], dc = sc + moves[i][1];
                if(isValid(dr, dc) && grid[dr][dc] == word[cont]){
                    if(cont != 0)
                         putchar(' ');
                    cont++;
                    printf("%s", dir[i].c_str());
                    sr = dr, sc = dc;
                    break;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}