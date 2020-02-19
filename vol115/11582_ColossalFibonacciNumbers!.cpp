#include <stdio.h>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vll;

ull squareExpMod(ull n, ull e, ull m){
    if(e == 0) return 1 % m;
    if(e % 2 == 0){
        ull aux = squareExpMod(n, e / 2, m);
        return ((aux % m) * (aux % m)) % m;
    }else{
        return ((n % m) * (squareExpMod(n, e - 1, m) % m)) % m;
    }
}

vll getCycle(int m){
    if(m == 1) return vll(1,0);
    int cont = 0;
    vll cycle = vll();
    cycle.push_back(0);
    cycle.push_back(1);
    while(true){
        cycle.push_back((cycle[cont] + cycle[cont + 1]) % m);
        cont++;
        if(cycle[cont] == 0 && cycle[cont + 1] == 1){
            cycle.pop_back();
            cycle.pop_back();
            return cycle;
        }
    }
}

int main(){
    int n, t;
    ull a, b;
    scanf("%d", &t);
    vector<vll> cycles = vector<vll>(1001);
    for(int i = 1; i <= 1000; i++){
        cycles[i] = getCycle(i);
    }
    while(t--){
        scanf("%llu %llu %d", &a, &b, &n);
        vll c = cycles[n];
        ull index = squareExpMod(a, b, c.size());
        printf("%llu\n", c[index]);
    }
    return 0;
}