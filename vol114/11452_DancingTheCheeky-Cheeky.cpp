#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	string s, pattern;
	while(n){
		cin >> s;
		int min = s.length() / 3 + 1;
		while(true){
			if(s.substr(0,min) == s.substr(min, min)){
				pattern = s.substr(0,min);
				break;
			}
			min++;
		}
		int dif = s.length() - 2 * min; 
		for(int i = 0; i < 8; i++){
			printf("%c",pattern[(i+dif)%min]);
		}
		printf("...\n");
		n--;
	}
	return 0;
}