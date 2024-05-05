#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    string s1, s2;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        cin >> s1 >> s2;
        int tokenCount1[3] = {0, 0, 0}, tokenCount2[2] = {0, 0}, dif = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '0') {
                tokenCount1[0]++;
            } else if (s1[i] == '1') {
                tokenCount1[1]++;
            } else if (s1[i] == '?') {
                tokenCount1[2]++;
            }
            if (s2[i] == '0') {
                tokenCount2[0]++;
            } else {
                tokenCount2[1]++;
            }
        }
        if (tokenCount1[0] + tokenCount1[2] < tokenCount2[0]) {
            cout << -1 << endl;
            continue;
        }

        int ans = tokenCount1[2];

        int dif0 = tokenCount2[0] - tokenCount1[0], dif1 = tokenCount2[1] - tokenCount1[1];
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '?') {
                if (s2[i] == '1' && dif1 > 0) {
                    s1[i] = '1';
                    dif1--;
                } else if (s2[i] == '0' && dif0 > 0) {
                    s1[i] = '0';
                    dif0--;
                } else if (dif0 > 0) {
                    s1[i] = '0';
                    dif0--;
                } else if (dif1 > 1) {
                    s1[i] = '1';
                    dif1--;
                }
            }
        }

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '0' && s2[i] == '1' && dif1 > 0) {
                ans++;
                dif1--;
                s1[i] = '1';
            }
        }
        for (int i = 0; i < s1.size(); i++) {
            dif += s1[i] != s2[i];
        }
        //cout << s1 << endl;
        cout << ans + dif / 2 << endl;

    }

    return 0;
}