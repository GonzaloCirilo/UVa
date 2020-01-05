#include <stdio.h>
#include <map>
using namespace std;
int main(){
    map<char,int> phoneKeyboard;
    phoneKeyboard['A'] = 2, phoneKeyboard['B'] = 2, phoneKeyboard['C'] = 2;
    phoneKeyboard['D'] = 3, phoneKeyboard['E'] = 3, phoneKeyboard['F'] = 3;
    phoneKeyboard['G'] = 4, phoneKeyboard['H'] = 4, phoneKeyboard['I'] = 4;
    phoneKeyboard['J'] = 5, phoneKeyboard['K'] = 5, phoneKeyboard['L'] = 5;
    phoneKeyboard['M'] = 6, phoneKeyboard['N'] = 6, phoneKeyboard['O'] = 6;
    phoneKeyboard['P'] = 7, phoneKeyboard['Q'] = 7, phoneKeyboard['R'] = 7, phoneKeyboard['S'] = 7;
    phoneKeyboard['T'] = 8, phoneKeyboard['U'] = 8, phoneKeyboard['V'] = 8;
    phoneKeyboard['W'] = 9, phoneKeyboard['X'] = 9, phoneKeyboard['Y'] = 9, phoneKeyboard['Z'] = 9;

    char c;

    while(scanf("%c", &c) != EOF){
        if(phoneKeyboard.find(c) != phoneKeyboard.end())
            printf("%d", phoneKeyboard[c]);
        else
            printf("%c", c);
    }
    return 0;
}