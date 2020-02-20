#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
struct BigNumber {
	int num[10000] = {}, size = 1;
	bool negative = false;
	BigNumber() { // default initializer to 0
		num[0] = 0;
	}
	BigNumber(int n) {
		int aux = n;
		negative = n < 0 ? true : false;
		size = 0;
		while (n) {
			num[size] = abs(n % 10);
			n /= 10;
			size++;
		}
		if (aux == 0)
			size = 1;
	}
	// TODO: Initializer from char array
	BigNumber(char n[]) {
		int cont = 0, lenght = strlen(n) - 1, digits = 1;
		if (n[0] == '-')
			this->negative = true;
		while (lenght && n[lenght] != '-') {
			this->num[cont++] = n[lenght - 1] - '0';
			if (this->num[cont - 1] != 0)
				digits = cont;
			lenght--;
		}
		this->size = digits;
	}
	static BigNumber absolute(BigNumber x) {
		x.negative = false;
		return x;
	}
	bool isZero() {
		return this->size == 1 && this->num[0] == 0;
	}
	BigNumber operator=(const int&n) {
		return BigNumber(n);
	}
	bool operator==(const BigNumber&n) {
		if (size == n.size && negative == n.negative) {
			for (int i = 0; i < size; i++) {
				if (num[i] != n.num[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
	bool operator!=(const BigNumber&n) {
		return !(*this == n);
	}
	bool operator<(const BigNumber&n) {
		if ((negative && !n.negative))
			return true;
		else if (!negative && n.negative)
			return false;
		else if (negative && size != n.size)
			return size > n.size;
		else if (!negative && size != n.size)
			return size < n.size;
		else {
			for (int i = size - 1; i >= 0; i--) {
				if (num[i] != n.num[i])
					return (!negative && num[i] < n.num[i]) || (negative && num[i] > n.num[i]);
			}
			return false;
		}

	}
	bool operator>(const BigNumber&n) {
		return !(*this < n) && !(*this == n);
	}
	bool operator<=(const BigNumber&n) {
		return !(*this > n);
	}
	bool operator>=(const BigNumber&n) {
		return !(*this < n);
	}
	BigNumber add(BigNumber x) {
		BigNumber res = BigNumber(0);
		int max = x.size > size ? x.size : size, carry = 0, d = 1;
		for (int i = 0; i < max; i++) {
			int s = (this->num[i] + x.num[i] + carry);
			res.num[i] = s % 10;
			if (s != 0)
				d = i + 1;
			carry = s / 10;
		}
		if (carry) {
			res.num[max] = carry;
			max++;
			d = max;
		}
		res.size = d;
		res.negative = this->negative;
		return res;
	}
	//dont use by itself
	BigNumber subs(BigNumber x) {//TODO fix size when
		int max = 0, carry = 0;
		BigNumber res = BigNumber(0);
		if (BigNumber::absolute(*this) > BigNumber::absolute(x)) {
			max = this->size;
			res = *this;
		}
		else {
			BigNumber aux = x;
			x = *this;
			res = aux;
			max = res.size;
			res.negative = !this->negative;
		}
		int d = 1;
		for (int i = 0; i < max; i++) {
			int s = (res.num[i] - x.num[i] - carry);
			res.num[i] = s < 0  && res.num[i+1]? s + 10 : abs(s);
			if (s != 0)
				d = i + 1;
			carry = s < 0 ? 1 : 0;
		}
		res.size = d;
		if (res.isZero())
			res.negative = false;
		return res;
	}
	BigNumber operator+(const BigNumber&x) {
		if (negative == x.negative){
			return this->add(x);
		}
		else {
			return this->subs(x);
		}
		//return *this;
	}
	void operator+=(const BigNumber&x) {
		*this = *this + x;
	}
	BigNumber operator-(const BigNumber&x) {
		if (negative == x.negative) {
			return this->subs(x);
		}
		else {
			return this->add(x);
		}
		//return *this;
	}
	void operator-=(const BigNumber&x) {
		*this = *this - x;
	}
	BigNumber operator*(const BigNumber&x) {
		int carry = 0;
		BigNumber result = BigNumber(0);
		for (int i = 0; i < size; i++) {
			BigNumber aux = BigNumber(0);
			int cont = i;
			for (int j = 0; j < x.size; j++) {
				int s = num[i] * x.num[j] + carry;
				aux.num[i + j] = s % 10;
				carry = s / 10;
				cont++;
			}
			while (carry > 0) {
				aux.num[cont++] = carry % 10;
				carry /= 10;
			}
			aux.size = cont;
			result += aux;
		}
		if (this->negative == x.negative)
			result.negative = false;
		else
			result.negative = true;
		return result;
	}
	BigNumber operator/(const BigNumber&x) {
		BigNumber res = BigNumber(0);

		return BigNumber(0);
	}
	void pow(BigNumber x) {


	}
	void print() {
		if (negative)
			printf("-");
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", num[i]);
		}
		printf("\n");
	}
};
int main(){
    vector<BigNumber> fib = vector<BigNumber>(5001);
    fib[0] = BigNumber(0);
    fib[1] = BigNumber(1);
    for(int i = 2; i <= 5000; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    while(scanf("%d", &n) != EOF){
        printf("The Fibonacci number for %d is ", n);
        fib[n].print();
    }
    return 0;
}