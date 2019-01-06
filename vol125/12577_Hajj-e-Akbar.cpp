#include <stdio.h>
int main(){
	char token[7]; int i = 1;
	while(fgets(token,7,stdin) && token[0] != '*'){
		printf("Case %d: ", i++);
		if(token[0] == 'H')
			printf("Hajj-e-Akbar\n");
		else
			printf("Hajj-e-Asghar\n");
	}
	return 0;
}