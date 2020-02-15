#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    char c = ' ';
    scanf("%d\n", &n);

    vector<pair<int, char>> arr = vector<pair<int,char>>(26, { 0,' ' });

    for(int i = 0; i < 26; i++){
        arr[i] = { 0, 'A' + i };
    }

    while(c != EOF){
        c = getchar();
        if((c - 'a' >= 0 && c - 'a' < 26) || (c - 'A' >= 0 && c - 'A' < 26)){
            int ind = toupper(c) - 'A';
            arr[ind].first++;
        }
    }

    sort(arr.begin(), arr.end(),[](const pair<int,char> &a, const pair<int,char> &b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;

    });

    for(int i = 0; i < 26; i++){
        if(!arr[i].first)
            break;
        printf("%c %d\n", arr[i].second, arr[i].first);
    }

    return 0;
}