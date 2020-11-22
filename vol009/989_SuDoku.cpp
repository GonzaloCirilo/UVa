#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef pair<vi, int> State;

bool allAppearOnce(vi grid){
    for(int i = 0; i < grid.size(); i++){
        if(grid[i] > 1)
            return false;
    }
    return true;
}

bool isComplete(vi grid, int n){
    for(int i = 0; i < n * n * n * n; i++){
        if(grid[i] == 0) return false;
    }
    return true;
}

void printGrid(vi grid, int n){
    for(int i = 0; i < n * n; i++){
        for(int j = 0; j < n * n; j++){
            if(j != 0) printf(" ");
            int ind = (i * (n * n)) + j;
            printf("%d", grid[ind]);
        }
        printf("\n");
    }
}

bool validCols(vi grid, int n){
    for(int i = 0; i < n * n; i++){
        vi appear = vi(n * n, 0);
        for(int j = i; j < n * n * n * n; j += (n * n)){
            if (grid[j] == 0) continue;
            appear[grid[j] - 1] += 1;
        }
        if(!allAppearOnce(appear)) return false;
    }
    return true;
}

bool validRows(vi grid, int n){
    for(int i = 0; i < n * n; i++){
        vi appear = vi(n * n, 0);
        for(int j = 0; j < n * n; j++){
            int ind = (i * (n * n)) + j;
            if(grid[ind] == 0) continue;
            appear[grid[ind] - 1] += 1;
        }
        if(!allAppearOnce(appear)) return false;
    }
    return true;
}

bool validSquares(vi grid, int n){
    for(int i = 0; i < n * n; i++){
        int si = (i % n) * n + (i / n) * (n * n * n); 
        vi appear = vi(n * n, 0);
        for(int j = 0; j < n * n; j++){
            int sj = si + (j % n) + (j / n) * (n * n);
            if(grid[sj] == 0) continue;
            appear[grid[sj] - 1] += 1;
        }
        if(!allAppearOnce(appear)) return false;
    }
    return true;
}

int main(){
    int n, cont = 0;

    while(scanf("%d", &n) != EOF) {
        if (cont != 0) printf("\n");

        vi grid;
        for(int i = 0; i < n * n; i++){
            for(int j = 0; j < n * n; j++){
                int aux;
                scanf("%d", &aux);
                grid.push_back(aux);
            }
        }

        stack<State> states;

        states.push({ grid, 0 });

        bool solved = false;

        while(!states.empty()){
            vi st = states.top().first; int ind = states.top().second; states.pop();

            if(!validCols(st, n) || !validRows(st,n) || !validSquares(st,n))
                continue;

            if(isComplete(st, n)){
                solved = true;
                printGrid(st, n);
                //printf("\n");
                break;
            }

            if(ind > (n * n * n * n)) continue;

            if (st[ind] != 0) {
                states.push({ st, ind + 1 });
                continue;
            }

            for(int j = 0; j < n * n; j++){
                vi aux = st;
                aux[ind] = (n * n) - j;
                if(validSquares(aux, n) && validRows(aux, n) && validCols(aux, n))
                    states.push({ aux, ind + 1 });
            }

        }

        if(!solved)
            printf("NO SOLUTION\n");

        cont++;

    }
    
    return 0;
}