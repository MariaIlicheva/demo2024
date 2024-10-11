#include <cmath>
#include <iostream>
 

int main(){

	for (double y = 1.5; y >= -1.5; y -= 0.15) {
		for (double x = -1.5; x <= 1.5; x += 0.075) {
			bool f = (pow((pow(x,2) + pow(y,2) - 1), 3) - pow(x,2)*pow(y,3) <= 0);
			char a = (f==1) ? '*' : '.';
			std::cout<<a;
		}
		std::cout<<std::endl;
	}
}