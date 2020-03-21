#include <stdio.h>
#include <sstream>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

int main(){
    int n, x, y;
    char lines[3000] = {};
    while(scanf("%d\n", &n) != EOF && n){
        int grid[100][100] = {};
        int visited[100][100] = {}, maxSet = 1, nset;
        for(int i = 0; i < n - 1; i++){
            nset = 0;
            fgets(lines, 3000, stdin);
            string s = lines;
            stringstream ss(s);
            while(ss >> x >> y){
                x--;y--;
                if(!grid[x][y]){
                    grid[x][y] = i + 1;
                    nset++;
                }
            }
            if(nset > maxSet)
                maxSet = nset;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    grid[i][j] = n;
            }
        }
        queue<pair<int, int>> q;
        int cont = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    cont++;
                    visited[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> a = q.front(); q.pop();
                        int v = grid[a.first][a.second];
                        for(int l = -1; l < 2; l+= 2){
                            if(a.first + l < n && a.first + l >= 0){
                                if(!visited[a.first + l][a.second] && grid[a.first + l][a.second] == v){
                                    visited[a.first + l][a.second] = 1;
                                    q.push({a.first + l, a.second});
                                }
                            }
                            if(a.second + l < n && a.second + l >= 0){
                                if(!visited[a.first][a.second + l] && grid[a.first][a.second + l] == v){
                                    visited[a.first][a.second + l] = 1;
                                    q.push({a.first, a.second + l});
                                }
                            }
                        }
                    }
                }
            }
        }
        // printf("===\n");
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         printf("%d", grid[i][j]);
        //     }
        //     printf("\n");
        // }

        // printf("===%d %d |%d\n", cont, maxSet, n);
        if(cont == n && maxSet == n)
            printf("good\n");
        else
            printf("wrong\n");

    }
    return 0;
}