#include <stdio.h>
bool fastScan(long long &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
void fastPrint(long long x){
	int i = 32;
	char output_buffer[32];
	do{
		output_buffer[--i]=(x%10)+'0';
		x/=10;
	}while(x);
	do{
		putchar(output_buffer[i]);
	}while(++i<32);
}
int main(){
    long long p;
    while(fastScan(p)){
        fastPrint(p - 1);
        putchar('\n');
    }
}