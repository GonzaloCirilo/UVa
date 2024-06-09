#include <stdio.h>
#include <ctype.h>
#include <map>
using namespace std;

int main () {
    char c;
    map<char, char> dict;
    dict['e'] = 'q';
    dict['d'] = 'a';
    dict['c'] = 'z';
    dict['r'] = 'w';
    dict['f'] = 's';
    dict['v'] = 'x';
    dict['t'] = 'e';
    dict['g'] = 'd';
    dict['b'] = 'c';
    dict['y'] = 'r';
    dict['h'] = 'f';
    dict['n'] = 'v';
    dict['u'] = 't';
    dict['j'] = 'g';
    dict['m'] = 'b';
    dict['i'] = 'y';
    dict['k'] = 'h';
    dict[','] = 'n';
    dict['o'] = 'u';
    dict['l'] = 'j';
    dict['.'] = 'm';
    dict['p'] = 'i';
    dict[';'] = 'k';
    dict['['] = 'o';
    dict['\''] = 'l';
    dict[']'] = 'p';
    while (true) {
        c = getchar();
        if (c == EOF) break;
        if (c < 15) continue;
        c = tolower(c);
        if (c == ' ') {
            putchar(c);
        } else {
            if ((dict[c] - 'a') >= 0 && (dict[c] - 'a') <= 26)
                putchar(dict[c]);
        }
    }
    putchar('\n');
}