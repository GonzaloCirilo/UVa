#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    string s;
    vector<string> sentences;
    int maxL = 0;
    while (getline(cin, s)) {
        sentences.push_back(s);
        maxL = max(maxL, (int)s.size());
    }
    for (int i = 0; i < maxL; i++) {
        for (int j = 0; j < sentences.size(); j++) {
            int index = sentences.size() - j - 1;
            if (sentences[index].size() <= i) {
                putchar(' ');
                continue;
            }
            putchar(sentences[index][i]);
        }
        putchar('\n');
    }
    return 0;
}