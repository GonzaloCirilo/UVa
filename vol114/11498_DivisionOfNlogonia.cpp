#include <stdio.h>
int main(){
	int q, n, m, x, y;
	while(scanf("%d", &q) && q){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < q; i++){
			scanf("%d %d", &x, &y);
			if(n-x==0||m-y==0)
				printf("divisa\n");
			else if(m-y < 0 && n-x>0){
				printf("NO\n");
			}
			else if(m-y < 0 && n-x<0){
				printf("NE\n");
			}
			else if(m-y > 0 && n-x<0){
				printf("SE\n");
			}
			else if(m-y > 0 && n-x>0){
				printf("SO\n");
			}
		}
	}
	return 0;
}