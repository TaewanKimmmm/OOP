//(실습 2) sum()은 임의의 파라미터들을 인자로 받아 합을 수행하는 함수이다.재귀적 호출 시
//컴파일 에러가 발생한다.원인을 생각해보고 결과값(63.6)이 출력되도록 코드를 완성하세요.
//(힌트: 마지막 sum 호출 시에는 파라미터가 하나만 남는다.Variadic template 활용에 대한
//   내용임)
//   ---------------------------------------------------- -
#include <iostream>
#include <string>


template<typename T>
auto sum(T x) {
	return x;
}

template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}


int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}
//--------------------------------------------------------

// 파라미터가 하나만 남는데, 하나만 받을 수 있는 함수가 없으니까
// sum(T x)로 하나의 인자를 받는 함수를 만들어준다.
