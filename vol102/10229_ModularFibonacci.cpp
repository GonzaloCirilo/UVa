#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int squareExp(int e){
    if(e == 0) return 1;
    if(e % 2 == 0){
        int aux = squareExp(e / 2);
        return aux * aux;
    }else{
        return 2 * squareExp(e - 1);
    }
}

int main(){
    int n, m;
    vvi map = vvi(20);
    map[0] = vi(1, 0);
    for(int i = 1; i < 20; i++){
        int modd = squareExp(i), cont = 0, p = 0, q = 1;
        map[i].push_back(p);
        map[i].push_back(q);
        while(true){
            map[i].push_back((map[i][cont] + map[i][cont+1]) % modd);
            cont++;
            if(map[i][cont] == 0 && map[i][cont + 1] == 1){
                map[i].pop_back();
                map[i].pop_back();
                break;
            }
        }
    }

    while(scanf("%d %d", &n, &m) != EOF){
        int cycle = map[m].size();
        printf("%d\n", map[m][n % cycle]);
    }
    return 0;
}