#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    string line;
    cin >> t;
    while (t--) {
        cin >> line;
        int open = 0, ans = 0;
        stack<int> ss;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '\\') {
                //cout << "pushing " << i << endl;
                ss.push(i);
            } else if (line[i] == '/') {
                if (!ss.empty()) {
                    int index = ss.top();
                    ss.pop();
                    ans += i - index;
                    //cout << "popping " << index << " at " << i  << "; ans = " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}