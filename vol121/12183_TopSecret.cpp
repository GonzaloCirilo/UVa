#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
typedef vector<long long> vll;
typedef vector<int> vi;

template <class T> bool fastScan(T &x) {
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

// A matrix mult time complexity is O(mnp) given Amn and Bnp
// For this special case we only need the first row of the result matrix
// so worst case O(n^2)
// ref http://web.mit.edu/18.06/www/Spring17/Circulant-Matrices.pdf
// 1.1 Multiplying by circulant matrices: Convolutions
void multMatrix(vll a, vll &b, int modd, int n){

    vll aux = vll(2002);
    long long sum;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            int idif = (i - j + n) % n;
            sum += a[j] * b[idif];
        }
        aux[i] = sum % modd;
    }

    b = aux;
}

int main(){

    int t, n, l, r, x;
    long long s;

    vll arr;

    fastScan(t);

    while(t--){
        fastScan(n);
        fastScan(s);
        fastScan(l);
        fastScan(r);
        fastScan(x);
        arr = vll(2002);
        int modd = (int)pow(10, x);

        for(int i = 0; i < n; i++){
            fastScan(arr[i]);
            arr[i] %= modd;            
        }
        getchar();

        vll circul = vll(2002);
        
        // this will be our "circulant matrix" represented as an array
        circul[0] = 1; circul[1] = l; circul[n - 1] = r;

        // solution is ((circul^s) * arr) but s is large 
        // so we need to use a fast exponentiation algorithm
        // https://www.geeksforgeeks.org/exponential-squaring-fast-modulo-multiplication/
        // using the 2k ary method
        while(s){
            // in the original algorithm the base should be identity matrix
            // but we can directly multiply arr here
            if(s % 2 == 1)
                multMatrix(circul, arr, modd, n);

            multMatrix(circul, circul, modd, n);
            s /= 2;
        }
        // total complexity O(log(s) * n * n)
        for(int i = 0; i < n; i++){
            if(i != 0)
                putchar(' ');
            printf("%lld", arr[i]);
        }
        putchar('\n');        
    }    
    return 0;
}