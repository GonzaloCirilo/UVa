#include <stdio.h>
#include <queue>
using namespace std;

int numToPile(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }else if(c == 'T'){
        return 10;
    }else if(c == 'J'){
        return 11;
    }else if(c == 'Q'){
        return 12;
    }else if(c == 'K'){
        return 13;
    }
    else if(c == 'A'){
        return 1;
    }
    return 0;
}

void solve(){
    char r, s, e;
    while(true){
        queue<char> rank[13], suit[13]; 
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                r = getchar();
                if(r == '#') return;
                rank[12 - j].push(r);
                s = getchar();
                suit[12 - j].push(s);
                e = getchar();
            }
            while(e != '\n'){
                e = getchar();
            }

        }

        char currN = rank[12].front(); rank[12].pop();
        char currT = suit[12].front(); suit[12].pop();
        int exposed = 1;
        int index = numToPile(currN) - 1;

        while(!rank[index].empty()){
            currN = rank[index].front(); rank[index].pop();
            currT = suit[index].front(); suit[index].pop();
            exposed++;
            index = numToPile(currN) - 1;
        }

        printf("%02d,%c%c\n", exposed, currN, currT);

    }
}

int main(){
    solve();
    return 0;
}