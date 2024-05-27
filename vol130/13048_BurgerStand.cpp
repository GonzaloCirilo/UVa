#include <string>
#include <iostream> 
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                if ((i + 1 < s.size() && s[i+1] == 'B') || (i + 2 < s.size() && s[i+2] == 'B')) {
                    continue;
                }
                if ((i + 1 < s.size() && s[i+1] == 'S') || (i - 1 >= 0 && s[i-1] == 'S')) {
                    continue;
                }
                ans++;
            }
        }
        cout << "Case " << ti << ": " << ans << endl; 
    }
    return 0;
}