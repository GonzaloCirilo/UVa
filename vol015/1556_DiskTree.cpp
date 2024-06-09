#include <iostream>
#include <string>
#include <map>
#include <regex>
using namespace std;

struct Directory {
    string name;
    map<string, Directory *> arr;
};

string getlinePlus() {
    string s;
    while (true) {
        char c = getchar();
        if (c == '\n' || c == EOF) 
            break;
        s.push_back(c);
    }
    return s;
}

vector<string> split(const string str, const string delimiter) {
    vector<string> res;
    size_t last = 0; size_t next = 0; 
    while ((next = str.find(delimiter, last)) != string::npos) {
        string token = str.substr(last, next-last);
        res.push_back(token);
        last = next + 1; 
    } 
    res.push_back(str.substr(last));
    return res;
}

void printDir(Directory *dir, int depth) {
    for (int i = 0; i < depth - 1; i++) {
        putchar(' ');
    }
    if (depth != 0) {
        printf("%s\n", dir->name.c_str());
    }
    if (dir->arr.size() == 0) 
        return;
    for (auto it = dir->arr.begin(); it != dir->arr.end(); it++) {
        printDir((*it).second, depth + 1);
    }
}

int main() {
    int n;
    string s;
    while (scanf("%d\n", &n) != EOF) {
        Directory* root = new Directory{"/", {}};
        while(n--) {
            s = getlinePlus();
            auto sp = split(s, "\\");
            Directory * aux = root;
            for(int i = 0; i < sp.size(); i++) {
                Directory * current = new Directory{sp[i], {}};
                if (aux->arr.find(sp[i]) == aux->arr.end()) {
                    aux->arr.insert({sp[i],current});
                } else {
                    current = aux->arr[sp[i]];
                }
                aux = current;
            }
        }
        printDir(root, 0);
        printf("\n");
    }
}