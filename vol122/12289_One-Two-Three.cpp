#include <stdio.h>
#include <string.h>
int main(){
	int t;
	char token[10];
	scanf("%d\n", &t);
	while(t){
		fgets(token, 10, stdin);
		int l = strlen(token) - 1;
		t--;
		if(l > 3){
			printf("3\n");
			continue;
		}
		int one = (int)(token[0] == 'o') + (int)(token[1] == 'n') + (int)(token[2] == 'e');
		int two = (int)(token[0] == 't') + (int)(token[1] == 'w') + (int)(token[2] == 'o');
		if(one > two)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}