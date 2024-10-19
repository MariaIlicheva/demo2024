#include <iostream>

int main() {
	int n;
	std::cin>>n;
	int deg = 1;
	int n_copy = n;
	const int base = 16;

	while (n_copy != 0) {
		n_copy /= base;
		deg *= base;
	}
	deg /= base;
	
	while (n != 0) {
		int dig = n / deg;
		char out_char;
		if (dig < 10) {
			out_char = dig + '0';
		}
		else {
			out_char = dig + 'A' - 10;
		}
		std::cout<<out_char;
		n %= base;
		deg/=base;
	}

	return 0;
}



