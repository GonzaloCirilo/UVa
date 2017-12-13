#include <stdio.h>
#include <vector> 
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi>Gi;
typedef pair<int, int>ii;
Gi grafo;
Vi visited, depths;
stack<ii>pile;
struct MyOperator
{//Sorting by max depth and lower number place
    bool operator() (ii const &a, ii const &b) { 
        return a.second < b.second || (!(b.second < a.second) && a.first > b.first);
    }
};
priority_queue<ii, vector<ii>, MyOperator>pq;
void DFS() {
    while (!pile.empty()) {
        int node = pile.top().first;
        int d = pile.top().second; pile.pop();
        for (int i = 0; i<grafo[node].size(); i++) {
            if (depths[grafo[node][i]] == 0 || depths[grafo[node][i]]<d) {
                depths[grafo[node][i]] = d;
                pq.push({ grafo[node][i],d + 1 });
                pile.push({ grafo[node][i],d + 1 });
            }
        }
    }
}

int main()
{
    int n, s;
    int c = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0)break;
        grafo = Gi(n);
        visited = Vi(n, 0);
        scanf("%d", &s);
        s--;
        while (true) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u == 0 && v == 0)
                break;
            u--; v--;
            grafo[u].push_back(v);
        }
        depths = Vi(n);
        pile.push({ s,0 });
        pq = priority_queue<ii, vector<ii>, MyOperator>();
        DFS();
        ii aux = !pq.empty() ? pq.top() : ii(s, 0);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", c, s + 1, aux.second, aux.first + 1);
        c++;
    }
    return 0;
}
