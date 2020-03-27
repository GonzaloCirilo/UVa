#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, char> ic;
typedef pair<int, int> ii;

struct Cmp{
    bool operator()(const ic& l, const ic& r)
    {
        if(l.first == r.first){
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};


int main(){
    int r, c, t = 1, n, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    scanf("%d", &n);
    while(n--){
        scanf("%d %d\n", &r, &c);
        char grid[500][500] = {}, visited[500][500] = {};
        printf("World #%d\n", t++);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = getchar();
            }
            getchar();
        }

        priority_queue<ic, vector<ic>, Cmp> pq;
        int states[28] = {};

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!visited[i][j]){
                    char token = grid[i][j];
                    queue<ii> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        ii u = q.front(); q.pop();
                        for(int k = 0; k < 4; k++){
                            ii v = {u.first+dr[k], u.second+dc[k]};
                            if(v.first >= 0 && v.first < r && v.second >= 0 && v.second < c && !visited[v.first][v.second] && grid[v.first][v.second] == token){
                                
                                q.push(v);
                                visited[v.first][v.second] = true;
                            }
                        }
                    }
                    states[token - 'a']++;
                }
                
            }
        }

        for(int i = 0; i < 28; i++){
            if(states[i] != 0){
                pq.push({states[i], (char)(i + 'a')});
            }
        }

        while(!pq.empty()){
            ic x = pq.top(); pq.pop();
            printf("%c: %d\n", x.second, x.first);
        }

    }
}