#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, char> ic;
typedef pair<int, int> ii;

struct Cmp
{
    bool operator()(const ic& l, const ic& r)
    {
        if(l.first == r.first){
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};


int main(){
    int r, c, t = 1, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while(scanf("%d %d\n", &r, &c) != EOF && r && c){
        char grid[52][52] = {}, visited[52][52] = {};
        printf("Problem %d:\n", t++);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = getchar();
            }
            getchar();
        }

        priority_queue<ic, vector<ic>, Cmp> pq;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] != '.' && !visited[i][j]){
                    int cont = 1;
                    char token = grid[i][j];
                    queue<ii> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        ii u = q.front(); q.pop();
                        for(int k = 0; k < 4; k++){
                            ii v = {u.first+dr[k], u.second+dc[k]};
                            if(v.first >= 0 && v.first < r && v.second >= 0 && v.second < c && !visited[v.first][v.second] && grid[v.first][v.second] == token){
                                cont++;
                                q.push(v);
                                visited[v.first][v.second] = true;
                            }
                        }
                    }
                    pq.push({cont, token});
                }
                
            }
        }

        while(!pq.empty()){
            ic x = pq.top(); pq.pop();
            printf("%c %d\n", x.second, x.first);
        }

    }
}