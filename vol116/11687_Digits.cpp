#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

int toInt(string s){
    stringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
}

string toString(int i){
    stringstream ss;  
    ss<<i;  
    string s;  
    ss>>s;
    return s;
}

int main(){
    while(true){
        char number[1000001];
        char c = ' ';
        fgets(number, 1000002, stdin);
        string s = string(number);

        if(s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
            break;
        int j = 0;
        s.erase(s.end() - 1, s.end());
        while(s.length() !=  toInt(s)){
            //cout<< "=======" << s << endl;
            s = toString(s.length());
            j++;
        }
        cout << j + 1 << endl;
    }
    return 0;
}