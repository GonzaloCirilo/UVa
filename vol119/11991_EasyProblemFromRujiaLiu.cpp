#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    int n, m, k, v;
    while(scanf("%d %d", &n, &m) != EOF){
        map<int, vi> freq;
        for(int i = 1; i <= n; i++){
            scanf("%d", &k);
            if(freq.find(k) == freq.end())
                freq[k] = vi();
            freq[k].push_back(i);
        }
        while(m--){
            scanf("%d %d", &k, &v);
            if(freq.find(v) != freq.end() && freq[v].size() >= k)
                printf("%d\n", freq[v][k - 1]);
            else
                printf("0\n");
        }
    }
    return 0;
}