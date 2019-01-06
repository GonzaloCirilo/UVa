#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int employees[3], t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d %d", &employees[0], &employees[1], &employees[2]);
		sort(employees,employees+3);
		printf("Case %d: %d\n", i+1,employees[1]);
	}
	return 0;
}