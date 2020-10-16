#include <iostream>
using namespace std;

class math {
public:
	void result(int x, int y) {
		cout << "The result is " << x + y << endl;
	}
	void result(int x, int y, int z) {
		cout << "The result is " << x + y + z << endl;
	}
};

int main() {

	math obj;
	obj.result(10, 15);
	obj.result(10, 5, 15);


	return 0;
}