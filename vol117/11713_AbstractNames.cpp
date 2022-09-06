#include <iostream>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    int n;
    string name, mut;
    cin >> n;
    while(n--){
        cin >> name >> mut;
        if(name.size() != mut.size()){
            cout << "No" << endl;
            continue;
        }
        bool same = true;
        for(int i = 0; i < name.size(); i++){
            if(isVowel(name[i]) && isVowel(mut[i])) continue;
            same = same && (name[i] == mut[i]);
        }
        if(same) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}