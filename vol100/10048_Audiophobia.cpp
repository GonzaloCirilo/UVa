#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> G;
vector<int> pset;

void init(int n){
    pset = vector<int>(n, -1);
}

int findSet(int p){
    if(pset[p] == -1)
        return p;
    return pset[p] = findSet(pset[p]);
}

bool isSameSet(int a, int b){
    return findSet(a) == findSet(b);
}

bool unionSet(int a, int b){
    if(!isSameSet(a, b)){
        pset[findSet(a)] = findSet(b);
        return true;
    }
    return false;
}

int main(){
    int c, s, q, u, v, db;
    int t = 0;
    while(scanf("%d %d %d", &c, &s, &q) != EOF  && (c || s || q)){
        if(t != 0) putchar('\n');
        init(c);
        printf("Case #%d\n", ++t);

        priority_queue<iii, vector<iii>, greater<iii>> pq;

        for(int i = 0; i < s; i++){
            scanf("%d %d %d", &u, &v, &db);
            u--,v--;
            pq.push({db, {u, v}});
        }

        int ed = 0;
        G graph = G(c);
        while(!pq.empty() && ed != c - 1){
            iii x = pq.top(); pq.pop();
            if(unionSet(x.second.first, x.second.second)){
                ed++;
                graph[x.second.first].push_back({x.first, x.second.second});
                graph[x.second.second].push_back({x.first, x.second.first});
            }
        }

        

        for(int i = 0; i < q; i++){
            scanf("%d %d", &u, &v);
            vector<int> visited = vector<int>(c, -1);
            u--, v--;
            queue<ii> q;
            visited[u] = 0;
            q.push({0, u});
            while(!q.empty()){
                ii aux = q.front(); q.pop();
                for(int j = 0; j < graph[aux.second].size(); j++){
                    ii y = graph[aux.second][j];
                    if(visited[y.second] == -1){
                        visited[y.second] = max(aux.first, y.first);
                        q.push({max(aux.first, y.first), y.second});
                    }
                }
            }
            if(visited[v] == -1)
                printf("no path\n");
            else
                printf("%d\n", visited[v]);

        }
    }
    return 0;
}