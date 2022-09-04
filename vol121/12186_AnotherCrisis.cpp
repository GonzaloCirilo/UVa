#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> g;
g graph;
int n, t;
int rec(int node) {
    if(graph[node].size() == 0) return 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < graph[node].size(); i++){
        int adj = graph[node][i];
        pq.push(rec(adj));
    }
    int min = ceil(1.0 * graph[node].size() * t / 100);
    int sum = 0;
    while(min--){
        auto x = pq.top(); pq.pop();
        sum += x;
    }
    return sum;
}

int main() {
    while(cin >> n >> t && (n != 0 && t != 0)){
        int u;
        graph = g(n + 1, vi());
        for(int i = 1; i <= n; i++){
            cin >> u;
            graph[u].push_back(i);
        }
        cout << rec(0) << endl;
    }
    return 0;
}