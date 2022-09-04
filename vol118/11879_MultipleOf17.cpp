#include <stdio.h>
#include <iostream>
#include <string>
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
    BigNumber(string s) {
        int cont = 0, lenght = s.size(), digits = 1;
		if (s[0] == '-')
			this->negative = true;
		while (lenght && s[lenght] != '-') {
			this->num[cont++] = s[lenght - 1] - '0';
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

    BigNumber operator++(int n){
        *this += BigNumber(1);
        return (*this);
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
			res.num[i] = s < 0  && (res.num[i+1] || i + 1 < res.size)? s + 10 : abs(s);
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
		if(isZero() || (x.size == 1 && x.num[0] == 0)){
			return BigNumber(0);
		}
		int carry = 0;
        int max = 0;
		BigNumber result = BigNumber(0);
		for (int i = 0; i < size; i++) {
            if(num[i] == 0) continue;
			int cont = i;
            carry = 0;
            int j;
			for (j = 0; j < x.size; j++) {
                int op = result.num[cont + j] + (num[i] * x.num[j]) + carry;
				result.num[cont + j] = op % 10;
                carry =  op / 10;
			}
            if(max < j + cont) max = j + cont;
            while(carry > 0){
                result.num[cont + j] = carry % 10;
                carry /= 10;
                if(max < j + cont + 1) max = j + cont + 1;
            }
		}
        result.size = max;
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
	BigNumber pow(int n) {
        if(n == 0) return BigNumber(1);

        if(n % 2 == 0){
            BigNumber aux = pow(n / 2);
            return aux * aux;
        }else{
            return (*this) * pow(n - 1);
        }
	}
	void print() {
		if (negative)
			printf("-");
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", num[i]);
		}
		printf("\n");
	}
    int toInt() {
        if(size >= 9) {
            return -1;
        }
        int integer = 0;
        for (int i = size - 1; i >= 0; i--) {
            integer *= 10;
            integer += num[i];
        }
        return integer;
    }
    string toString() {
        string s;
        if (negative)
			s.push_back('-');
		for (int i = size - 1; i >= 0; i--) {
			s.push_back(num[i] + '0');
		}
        return s;
    }
};

int main() {
   
    string s;
    while(cin >> s && s != "0") {
        auto n = BigNumber(s);
        bool ans = false;
        int cont = 1;
        while(n.size > 8) {
            auto aux = BigNumber(s.substr(0, s.size() - 1));
            auto delta = BigNumber(n.num[0] * 5);
            //aux.print();
            //delta.print();
            n = aux - delta;
            //n.print();
            s = n.toString();
            cont++;
            //cout << "=========" << endl;
        }
        //cout << "int " << n.toInt() << endl;
        if(n.toInt() % 17 == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

    }
    return 0;
}