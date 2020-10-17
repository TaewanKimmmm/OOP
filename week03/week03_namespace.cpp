#include <iostream>



int a = 1000;

namespace N {
	int a = 10;

	void printN() {
		int a = 100;
		std::cout << a << std::endl;
		std::cout << N::a << std::endl;
	}
}

int main() {

	std::cout << "test!" << std::endl;
	N::printN();
	return 0;
}