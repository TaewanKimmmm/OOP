#include <iostream>
#include <stdexcept>
class Test {

public:
	Test(char id) : id_(id) {}

	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}

private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* 

(�ǽ� 1-1) �м���� : 

�Լ� ȣ�� ������ ������ �����ϴ�.

main -> funcA() -> funcB()

���� ����� �Ʒ��� �����ϴ�.

Executed in B
Destructor execution: B
Executed in A
Destructor execution: A

�м��� �Ʒ��� �����ϴ�.

funcA()���� id A�� ������ Test ��ü�� ������ ���� funcB()�� ����, funcB()���� id B�� ������ Test ��ü�� �����մϴ�. 

Executed in B ������ ������ ������ ����ǰ�, ���Ϲ��� ����Ǹ� funcB()�� ����ʰ� ���ÿ� �Ҹ���(�ı���)�� ����˴ϴ�.

���� funcA()���� funcB() ȣ�� ��ġ�� ���� ������ Executed in A ������ ����ϰ� funcA() ���Ϲ��� ����Ǹ� �Ҹ���(�ı���)�� ����˴ϴ�.

*/


/* 

(�ǽ� 1-2) �м���� : 

���� ����� �Ʒ��� �����ϴ�.

Destructor execution: B
Destructor execution: A
Exception : Exception from funcB!

�м��� �Ʒ��� �����ϴ�.

funcB()���� ��ü�� ������ ���� exception�� throw�ϴµ�, 

���ܰ� �߻��ϰ� �Ǹ� ���ܸ� ���Ľ�Ű�� �˴ϴ�.

catch �κ����� ���� �ϸ鼭, �Լ��鿡 �ִ� ��ü���� ������Ű��, 

���� ���ܸ� ������ �κ� ���Ŀ� ����Ǿ�� �� �ڵ���� ������� �ʽ��ϴ�.

�̿� ���� catch �� ���� �ϸ鼭 ���� �󿡼� ���ǵ� ��ü���� �Ҹ��Ű�� ������ ���� Ǯ��(stack unwinding)��� �մϴ�.

*/