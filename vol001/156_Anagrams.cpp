#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    map<string, vector<string>> mapped;
    while (true) {
        string token, sorted;
        cin >> token;
        if (token == "#") break;
        sorted = token;
        transform(sorted.begin(), sorted.end(), sorted.begin(),[](unsigned char c){ return tolower(c); });
        sort(sorted.begin(), sorted.end());
        mapped[sorted].push_back(token);
        
    }
    set<string> ss;
    for (auto it = mapped.begin(); it !=  mapped.end(); it++) {
        //cout << "=====" << (*it).first << " "<< (*it).second.size() << endl;
        if ((*it).second.size()  == 1) {
            ss.insert((*it).second[0]);
        }
    }
    for (auto ans : ss) {
        cout << ans << endl;
    }
    return 0;
}
