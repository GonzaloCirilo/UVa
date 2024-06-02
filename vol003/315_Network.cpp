#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

vi times, low, visited, parent;
int t, root, children;
graph g;
vector<bool> ans;

void DFS(int u) {
    visited[u] = 1;
    times[u] = t++;
    low[u] = times[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!visited[v]) {
            parent[v] = u;
            if (u == root) {
                ++children;
            }
            DFS(v);
            
            if (low[v] >= times[u] && u != root) {
                ans[u] = true;
            }
            low[u] = min(low[u], low[v]);
        } else if(v != parent[u]) {
            low[u] = min(low[u], times[v]);
        } 
    }
}

int main() {
    int n, u, v;
    while (true) {
        string s;
        getline(cin, s);
        stringstream str = stringstream(s);
        str >> n;
        if (n == 0) break;
        ans = vector<bool>(n, false);
        //cout << "--n" << n << endl;
        g = graph(n);
        while (true) {
            getline(cin, s);
            if (s == "0") break;
            stringstream ss = stringstream(s);
            ss >> u;
            u--;
            //cout << s << "--u" << u << endl;
            while (ss >> v) {
                //cout << "--v" << v << endl;
                v--;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        t = 0;
        visited = vi(n, 0);
        times = vi(n, -1);
        low = vi(n, -1);
        parent = vi(n, -1);

        for (int  i = 0; i < n; i++) {
            if (!visited[i]) {
                root = i;
                children = 0;
                DFS(i);
                ans[i] = children > 1;
            }
        }
        int count = 0;
        for(int i = 0; i < ans.size(); i++) {
            count += (ans[i]);
        }

        cout << count << endl;
    }
    return 0;
}