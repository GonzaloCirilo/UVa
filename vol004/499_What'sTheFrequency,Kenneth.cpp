#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    while(true){
        char c;
        int lower[26] = {}, upper[26] = {};
        while(true){

            c = getchar();
            if(c == '\n' || c == EOF) break;
            
            if(c >= 'a' && c <= 'z'){
                lower[c - 'a']++;
            }else if(c >= 'A' && c <= 'Z'){
                upper[c - 'A']++;
            }
        }

        int maxe = max(*max_element(lower, lower + 26), *max_element(upper, upper + 26));
        if(maxe == 0) break;
        for(int i = 0; i < 26; i++){
            if(maxe == upper[i]){
                putchar('A' + i);
            }
        }
        for(int i = 0; i < 26; i++){
            if(maxe == lower[i]){
                putchar('a' + i);
            }
        }
        printf(" %d\n", maxe);


        if(c == EOF) break;
    }
    return 0;
}