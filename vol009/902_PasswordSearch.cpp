#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int main(){
	int n; string s;
	while(cin >> n >> s){
		map<string,int> hash;
		for(int i = 0; i < s.length() - n + 1; i++){
			hash[s.substr(i,n)] += 1;
		}
		string ans; int value = 0;
		for(auto it = hash.begin(); it != hash.end(); ++it){
			if(it->second > value){
				value = it->second;
				ans = it->first;
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}