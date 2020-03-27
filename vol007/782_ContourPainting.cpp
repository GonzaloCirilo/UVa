#include <stdio.h>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
typedef pair<int,int>ii;
int inf = 10000;
int getValue(char c){
    int v;
    switch(c){
        case ' ':
            v = 0;
            break;
        case '*':
            v = 0;
            break;
        case '\n':
            v = 0;
            break;
        default:
            v = (int)c;
    }
    return v;
}
int main(){
    ii moves[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    char c; string lines;
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    int i, j;
    while(n--){
        int grid[100][100] = {}, visited[100][100] = {}, maxInd[100] = {};
        i = 0;
        ii s;
        while(getline(cin, lines)){
            if(lines[0] == '_') break;

            for(int j = 0; j < lines.size(); j++){
                if(lines[j] == '*')
                    s = {i,j};
                visited[i][j] = getValue(lines[j]);
                grid[i][j] = getValue(lines[j]);
            }
            i++;
        }
        queue<ii> q;
        q.push(s);
        visited[s.first][s.second] = inf;
        while (!q.empty()){
            ii u = q.front(); q.pop();
            bool nearWall = false;
            for(int k = 0; k < 4; k++){
                ii v = {u.first + moves[k].first, u.second + moves[k].second};
                if(v.first >= 0 && v.first < i && v.second >= 0 && v.second < 99){
                    if(!visited[v.first][v.second]){
                        visited[v.first][v.second] = inf;
                        q.push(v);
                    }
                    if(grid[v.first][v.second] != 0 && grid[v.first][v.second] != (int)'#'){
                        nearWall = true;
                    }
                }
            }
            if(nearWall)
                grid[u.first][u.second] = (int)'#';
        }

        for(int k = 0; k < i; k++){
            for(int l = 0; l < 82; l++){
                if(grid[k][l] != 0){
                    maxInd[k] = l + 1;
                }
            }
        }

        for(int k = 0; k < i; k++){
            for(int l = 0; l < maxInd[k]; l++){
                if(grid[k][l] == 0){
                    putchar(' ');
                }else{
                    putchar((char)grid[k][l]);
                }
            }
            putchar('\n');
        }
        for(auto it = lines.begin(); it != lines.end(); it++){
            putchar(*it);
        }
        putchar('\n');
        
    }
    return 0;
}