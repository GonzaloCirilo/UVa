#include <stdio.h>
int main(){
	int t, donations = 0, amount;
	char token[40];
	scanf("%d\n", &t);
	while(t--){
		fgets(token, 40, stdin);
		if(token[0] == 'r')
			printf("%d\n", donations);
		else{
			char cmd[10];
			sscanf(token, "%s %d", &cmd, &amount);
			donations += amount;
		}
	}
	return 0;
}