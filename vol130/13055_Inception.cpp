#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int n;
    string name, cmd;
    scanf("%d\n", &n);
    stack<string> inception;
    while(n--){
        cin >> cmd;
        switch (cmd[0])
        {
        case 'S':
            cin >> name;
            inception.push(name);
            break;
        case 'T':
            if(!inception.empty())
                cout << inception.top() << endl;
            else
                cout << "Not in a dream" << endl;
            break;
        case 'K':
            if(!inception.empty())
                inception.pop();
        default:
            break;
        }
    }
    return 0;
}