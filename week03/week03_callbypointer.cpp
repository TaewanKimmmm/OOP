#include <iostream>

void increment(int* input) {
	(*input)++;
}

int main() {

	int x = 10;
	
	//int* address_of_x = &x;
	//increment(address_of_x);

	increment(&x);
	std::cout << x << std::endl;

	return 0;
}