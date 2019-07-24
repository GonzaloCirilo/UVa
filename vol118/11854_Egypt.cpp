#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int sides[3];

    while(scanf("%d %d %d", &sides[0], &sides[1], &sides[2]) 
        && (sides[0] || sides[1] || sides[2])){
        sort(sides, sides + 3);
        if(sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2] && sides[0] != 1 && sides[1] != 1){
            printf("right\n");
        }else{
            printf("wrong\n");
        }        
    }
    return 0;
}