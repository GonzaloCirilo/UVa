#include <stdio.h>
#include <math.h>
void fastScan(long &x){
    bool neg = false;
	register long c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}
int main(){
	double n;
	long aux;
	while(true){
		fastScan(aux);
		if(!aux) break;
		n = (double) aux;
		if(pow((int)sqrt(n),2) == n)
			printf("yes\n");
		else
			printf("no\n");
	} 
	return 0;
}