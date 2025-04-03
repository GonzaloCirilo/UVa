#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;

int main() {
    int n, x1, y1, x2, y2;
    while (scanf("%d", &n) != EOF) {
        int ind = 0;
        G graph = G();
        map<pair<int, int>, int> coordToIndex;
        vector<bool> visited;
        while (n--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (coordToIndex.find({x1, y1}) == coordToIndex.end()) {
                coordToIndex[{x1, y1}] = ind++;
                graph.push_back(vi());
            }
            if (coordToIndex.find({x2, y2}) == coordToIndex.end()) {
                coordToIndex[{x2, y2}] = ind++;
                graph.push_back(vi());
            }
            graph[coordToIndex[{x1, y1}]].push_back(coordToIndex[{x2, y2}]);
            graph[coordToIndex[{x2, y2}]].push_back(coordToIndex[{x1, y1}]);
        }
        visited = vector<bool>(graph.size(), false);
        int ans = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                stack<int> s;
                s.push(i);
                while (!s.empty()) {
                    int u = s.top();
                    s.pop();
                    for (int j = 0; j < graph[u].size(); j++) {
                        int v = graph[u][j];
                        if (!visited[v]) {
                            visited[v] = true;
                            s.push(v);
                        }
                    }
                }
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}