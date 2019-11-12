#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++){
        int pointer = 0, arr[101] = {};
        char c = ' ';
        while(c != '\n'){
            c = getchar();
            if(c == '+'){
                arr[pointer] = (arr[pointer] + 1) % 256;
            }else if(c == '-'){
                arr[pointer] = (arr[pointer] + 255) % 256;
            } else if(c == '<'){
                pointer = (pointer + 99) % 100;
            } else if(c == '>'){
                pointer = (pointer + 1) % 100;
            }
        }
        cout << dec << "Case " << i << ":";
        for(int j = 0; j < 100; j++){
            cout << " " << setw(2)<< setfill('0') << uppercase <<  hex << arr[j];
        }
        cout << endl;
    }
    return 0;
}