#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n){
        

        int ans = 1;
        int ended = 0, cont = n;
        while(ended != 12 || cont != 1){
            cont = n;
            // starting simulation
            vector<int> arr = vector<int>(n, 0);
            arr[0] = 1;
            int index = 1, it = 0;
            while(cont){
                if(arr[it]){
                    it = (it + 1) % n;
                    continue;
                }

                if(index == ans){
                    arr[it] = 1;
                    index = 0;
                    ended = it;
                    cont--;
                    if(ended == 12)
                        break;
                }
                index++;
                it = (it + 1) % n;

            }

            //simulation ended
            ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
