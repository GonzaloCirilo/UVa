#include <stdio.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
typedef vector<int> vi;
vi grid;
int n, m, k, modBit;
bool found;

int circularRightShift(int x, unsigned int s){
    return (x >> s) | (x << m - s);
}
int circularLeftShift(int x, unsigned int s){
    return (x << s) | (x >> m - s);
}
int bitExtracted(int x, int _m, int p){ // extract the bits from p to _m
    return (((1 << _m) - 1) & (x >> (p - 1)));
}
int gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    if (a == b)
        return a;
  
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void bitwiseNQueens(int col, int ld, int rd, int ck, int d){ 
    if (found || d > n || (k - ck > n - d)) return;
    if (ck == k){
        found = true;
        for(int i = 0; i < grid.size(); i++){
            if(grid[i]){
                int c = i % m;
                int r = i / m;
                printf("%d %d\n", c + 1, r + 1);
            }
        }
        return;
    }
    
    int poss = col & ld & rd, res = 0;
    while(poss & -poss){
        int bit = poss & -poss; 
        poss ^= bit;
        int auxInd = 0;
        int auxBit = modBit;
        for(int i = 0; i < m; i++){
            if((bit >> i) & 1){
                auxInd = i;
                break;
            }
            auxBit = bitExtracted(circularLeftShift(auxBit, 1),m,1);
        }
        auxInd = d * m + auxInd;
        
        
        if(d < n){
            grid[auxInd] = 1;
            if(!found)
                bitwiseNQueens(col ^ bit, bitExtracted(circularLeftShift(bitExtracted(ld ^ auxBit, m, 1), 1), m, 1), bitExtracted(circularRightShift(bitExtracted(rd ^ auxBit, m, 1), 1), m, 1), ck + 1, d+1);
            grid[auxInd] = 0;

        }
    }
    if(!found && d != 0)
       bitwiseNQueens(col, circularLeftShift(ld, 1), circularRightShift(rd, 1), ck, d+1);
    return ;
}
// The algorithm is a modification of the problems uva 11195
int main(){
    int c = 1;
    while(scanf("%d %d %d\n", &m, &n, &k) != EOF){
        //printf("Case #%d: ", c++);
        grid = vi(n*m, 0);
        
        found = false;
        modBit = 1;
        int shift = gcd(m,n);
        for(int i = 0; i < m - shift; i += shift){
            modBit = bitExtracted(circularLeftShift(modBit, shift) | 1, m, 1);
        }
        bitwiseNQueens((1 << m) - 1, (1 << m) - 1, (1 << m) - 1, 0, 0);

        if(!found)
            printf("%d %d\n", 0, 0);
    }

    return 0;
}