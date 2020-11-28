//(실습1)아래 코드를 실행해 보고 템플릿의 default parameter 용법에 대해 익혀보세요.실행
//결과 값은 ? x : 8
//----------------------------------------------------------------

#include <iostream>
template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl;
}
//---------------- -