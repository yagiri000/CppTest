#include <iostream>
#include <memory>
#include <string>

void Hoge(int a, const std::string& str) {
	std::cout << "hoge " << a << str << std::endl;
}



int main() {
	auto timeFuncInvocation =
		[](auto && func, auto&&... params) {
		std::cout << "start" << std::endl;
		std::forward<decltype(func)>(func)(
			std::forward<decltype(params)>(params)...
			);
		std::cout << "end" << std::endl;
	};

	timeFuncInvocation(Hoge, 10, "hoge");
	return 0;
}
