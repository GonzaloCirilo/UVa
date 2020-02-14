#include <stdio.h>
#include <vector>
using namespace std;

void insert(vector<int> &v, int n){
    for(auto it = v.begin(); it != v.end(); it++){
        if(*it > n){
            v.insert(it, n);
            return;
        }
    }
    v.push_back(n);
}
int main(){
    int n, cont = 0;
    vector<int> arr;
    while(scanf("%d", &n) != EOF){
        cont++;
        if(cont == 1)
            arr.push_back(n);
        else{
            insert(arr, n);            
        }

        if(cont % 2 == 0){
            int ind1 = cont / 2, ind2 = ind1 - 1;
            printf("%d\n", (arr[ind1] + arr[ind2]) / 2);
        }else{
            printf("%d\n", arr[cont / 2]);
        }
    }
    return 0;
}