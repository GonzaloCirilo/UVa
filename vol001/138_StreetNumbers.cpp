#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<pair<int,int>> ans = {{1,1}, {6,8}};

    for(int i = 2; i <= 10; i++){
        int house = ans[i-1].first * 6 - ans[i-2].first;
        int max = house + ans[i-1].first + ans[i-1].second;
        ans.push_back({house, max});
    }

    for(int i = 1; i <= 10; i++){
        printf("%10d%10d\n", ans[i].first, ans[i].second);
    }

    return 0;
}