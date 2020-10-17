#include <iostream>



class A {

private:
	int x;

public:
	A(int input) :x(input) {
		std::cout << "Object Constructed! input is " << input << std::endl;
	}

	int return_x() {
		return x;
	}

	int& return_ref_x() {
		return x;
	}

	void print_status() {
		std::cout << x << std::endl;
	}
};

int main() {

	A a(5);
	a.print_status();	

	int& ref = a.return_ref_x();
	ref++;
	a.print_status();

	int temp = a.return_ref_x(); // copy of value
	std::cout << temp << std::endl;

	return 0;
}