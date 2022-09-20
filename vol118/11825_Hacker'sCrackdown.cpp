#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int n, k, v, t = 1;
const int topValue = (1 << 16) + 10;
int main(){
    G graph;
    while(scanf("%d", &n) != EOF && n){
        graph = G(n);
        //printf("\n=========\n");
        for(int i = 0; i < n; i++){
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                scanf("%d", &v);
                //printf("%d ", v);
                graph[i].push_back(v);
            }
            //printf("\n");
        }

        //printf("=========\n");
        int ans = 0;
        int maxMask = (1 << n) - 1;
        int isInSolutions[topValue] = {};
        vi solutions = vi();
        for(int mask = 0; mask<(1<<n); mask++){
            int discoveredMask = 0;
            for(int i=0; i<n; i++) {
                if(mask & (1<<i)){
                    discoveredMask |= (1 << i);
                    for(int j = 0; j < graph[i].size(); j++) {
                        discoveredMask |= (1 << graph[i][j]);
                    }
                }
            }

            if(discoveredMask == maxMask) {
                solutions.push_back(mask);
                isInSolutions[mask] = 1;
            }
        }

        int dp[topValue] = {};
        for(int i = 0; i < solutions.size(); i++) {
            for(int sol = solutions[i]; sol; sol = (sol - 1) & solutions[i]) {
                if(isInSolutions[sol])
                    dp[solutions[i]] = max(dp[solutions[i]], dp[sol ^ solutions[i]] + 1);
            }
        }

        printf("Case %d: %d\n", t++, dp[maxMask]);
    }
    return 0;
}