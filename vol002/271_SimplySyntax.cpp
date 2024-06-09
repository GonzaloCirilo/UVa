#include <string>
#include <stack>
using namespace std;

int main() {
    char cs[256];
    while (scanf("%s\n", cs) != EOF) {
        string s(cs);
        stack<char> st;
        bool correctness = true;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            auto c = (*it);
            if ((c - 'a') >= 0 && (c - 'a') <= 26) {
                st.push(c);
            } else {
                if (c == 'N') {
                    if (st.size() == 0) {
                        correctness = false;
                        break;
                    }
                    st.pop();
                    st.push(c);
                } else {
                    if (st.size() <= 1) {
                        correctness = false;
                        break;
                    }
                    st.pop();
                    st.pop();
                    st.push(c);
                }
            }
            
        }
        if (st.size() != 1) {
            correctness = false;
        }
        if (correctness) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}