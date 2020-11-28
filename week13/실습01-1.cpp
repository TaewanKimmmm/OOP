//(실습1.1) 위 add_num 함수의 결과값이 5 가 나오도록(즉, return t + 2) 가 되도록 main
//함수에서 add_num() 호출 부분을 수정해 보시오.

#include <iostream>
template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num(x - 3) << std::endl;
}
//---------------- -