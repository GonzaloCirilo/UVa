#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getDestGroup() {
    int n;
    int graph[27][27] = {};
    cin >> n;
    int visited[27] = {};
    while(n--) {
        char u, v;
        cin >> u >> v;
        graph[u-'A'][v-'A'] = 1;
        graph[v-'A'][u-'A'] = 1;
        visited[u-'A'] = -1;
        visited[v-'A'] = -1;
    }
    vector<int> destinations = vector<int>();
    for(int i = 0; i < 26; i++) {
        if (visited[i] >= 0) continue;
        // bfs
        int dBit = 0;
        queue<int> q;
        q.push(i);
        visited[i]= 1;
        dBit |= 1 << (i+1);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int j = 0; j < 26; j++) {
                if(graph[node][j] == 0) continue;
                int adj = j;
                if (visited[adj] == -1) {
                    q.push(adj);
                    visited[adj] = 1;
                    dBit |= 1 << (adj+1);
                }
            }
        }
        destinations.push_back(dBit);
    }
    sort(destinations.begin(), destinations.end());
    return destinations;
}

bool areEqual(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i != 0) cout << endl;
        auto destinationsA = getDestGroup(), destinationsB = getDestGroup();
        if (areEqual(destinationsA, destinationsB)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}