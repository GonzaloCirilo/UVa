#include <stdio.h>
int main(){
	char token [1001];
	while(fgets(token, 1001, stdin)){
		printf("%s", token);
	}
	return 0;
}