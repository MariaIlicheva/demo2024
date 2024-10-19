#include <iostream>
#import<cmath>

int bin_to_dec(int n){
	int base = 1;
	int dec = 0, i = 0, c;
	while (n!=0){
		c = n%10;
		n /=10;
		dec += c*base;
		base *= 2;
	}

	return dec;
}

void dec_to_bin_rec(int n){
	if (n/2 != 0) dec_to_bin_rec(n/2);
	std::cout<<n%2;
}

int dec_to_bin(int n) {
	int len = 1;
	int k = 2;
	while (k<=n){
		len*=10;
		k*=2;

	}
	int bin = 0, b = 1;
	while (n%len!=0){
		int d = (n%2 == 0) ? 0: 1*b;
		n/=2;
		b*=10;
		bin += d;
	}
	return bin;
}

void dec_to_hex(int n) {

    char hexDigits[] = "0123456789ABCDEF";
    char hex[32]; // массив для хранения числа_16
    int i = 0;

    if (n == 0) hex[i++] = '0';
    else {
        while (n > 0) {
            int r = n%16; 
            hex[i++] = hexDigits[r];
            n /= 16;
        }
    }
    
    for (int j = i-1; j >= 0; --j) {
        std::cout << hex[j];
    }
    std::cout << std::endl;
}


int main(){
	int n;
	std::cin>>n;
	//std::cout << "no rec " << dec_to_bin(n) << std::endl;
	//std::cout<<bin_to_dec(n) << std::endl;
	//dec_to_bin_rec(n);
	//std::cout << dec_to_bin(n) << std::endl;
	dec_to_hex(n);
}



