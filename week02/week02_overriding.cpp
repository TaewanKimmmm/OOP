#include <iostream>
using namespace std;


class base {
public:
	void output() {
		cout << "Its Base Class: " << endl;
	}
};

class derived: public base {
public:
	void output(){
		cout << "Its Derived Class: " << endl;
	}
};

int main() {
	base parent;
	derived child;

	parent.output();
	child.output();

	return 0;
}