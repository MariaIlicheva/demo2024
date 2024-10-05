#include <iostream>

int main() {
/*
	int n;
	std::cin >> n;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
*/
	int n;
	std::cin >> n;
	for (int i = 1; i < n + 1; i+=2) {
		int col = (n - i) / 2;
		bool f = false;
		for (int j = 0; j < i; ++j) {
			if (not f) {
				for (int c = 0; c < col; ++c) {
					std::cout << ' ';
				}
				f = true;
			}
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	n -= 2;
	for (int i = n; i > 0; i -= 2) {
		int col = (n - i) / 2+1;
		bool f = false;
		for (int j = 0; j < i; ++j) {
			if (not f) {
				for (int c = 0; c < col; ++c) {
					std::cout << ' ';
				}
				f = true;
			}
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}