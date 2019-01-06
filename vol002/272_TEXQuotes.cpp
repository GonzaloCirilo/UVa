#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main() {
	char token[1001];int cont = 1;
	while(fgets(token,1001,stdin)){
		int l = strlen(token);
		string ans;
		for(int i = 0; i < l; i++){
			if(token[i] == '\"'){
				if(cont % 2 == 0){
					ans.push_back('\'');
					ans.push_back('\'');
				}
				else{
					ans.push_back('`');
					ans.push_back('`');
				}
				cont++;
				continue;
			}
			ans.push_back(token[i]);
		}
		printf("%s", ans.c_str());
	}
	return 0;
}