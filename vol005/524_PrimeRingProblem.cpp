#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool primes[32] = { };
void rec(int n, vector<int> arr, set<int> re){
    if(arr.size() == n && primes[arr[0] + arr[n - 1]]){
        for(int i = 0; i < arr.size(); i++){
           if(i) printf(" ");
           printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }
    for(auto it = re.begin(); it != re.end(); it++){
        if(primes[*it + arr[arr.size() - 1]]){
            auto aux = re;
            aux.erase(*it);
            arr.push_back(*it);
            rec(n, arr, aux);
            arr.pop_back();
        }
    }
}
int main(){
    int n;    
    primes[2] = true, primes[3] = true, primes[5] = true;
    primes[7] = true, primes[11] = true, primes[13] = true;
    primes[17] = true, primes[19] = true, primes[23] = true, primes[29] = true, primes[31] = true;
    int cs = 1; 
    while(scanf("%d", &n) != EOF){
        if(cs != 1)
            printf("\n");
        printf("Case %d:\n", cs++);
        set<int> s = set<int>();
        for(int i = 2; i <= n; i++){
            s.insert(i);
        }
        rec(n, vector<int>(1, 1), s);
        //printf("\n");
    }
    return 0;
}