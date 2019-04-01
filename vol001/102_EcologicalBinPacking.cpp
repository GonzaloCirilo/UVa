#include <stdio.h>
#include <climits>
#include <string>
using namespace std;
void fastScan(int &x){
    bool neg = false;
	register int c;
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
	int bins[3][3], ans, aux;
	while(scanf("%d", &bins[0][0]) != EOF){
		ans = INT_MAX;
		string s;
		for(int i = 1; i < 9; i++){
			fastScan(bins[i/3][i%3]);
		}
		//BCG
		aux = bins[0][1] + bins[0][2] + bins[1][0] + bins[1][1] + bins[2][0] + bins[2][2];
		if(aux < ans){
			s = "BCG";
			ans = aux;
		}
		

		//BGC
		aux = bins[0][1] + bins[0][2] + bins[1][0] + bins[1][2] + bins[2][0] + bins[2][1];
		if(aux < ans){
			s = "BGC";
			ans = aux;
		}		

		//CBG
		aux = bins[0][0] + bins[0][1] + bins[1][1] + bins[1][2] + bins[2][0] + bins[2][2];
		if(aux < ans){
			s = "CBG";
			ans = aux;
		}


		//CGB
		aux = bins[0][0] + bins[0][1] + bins[1][0] + bins[1][2] + bins[2][1] + bins[2][2];
		if(aux < ans){
			s = "CGB";
			ans = aux;
		}
		
		//GBC
		aux = bins[0][0] + bins[0][2] + bins[1][1] + bins[1][2] + bins[2][0] + bins[2][1];
		if(aux < ans){
			s="GBC";
			ans = aux;
		}
		
		//GCB
		aux = bins[0][0] + bins[0][2] + bins[1][0] + bins[1][1] + bins[2][1] + bins[2][2];
		if(aux < ans){
			s="GCB";
			ans = aux;
		}
		
		printf("%s %d\n", s.c_str(), ans);
	}
}