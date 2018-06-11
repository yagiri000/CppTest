#include <iostream>
#include <memory>
#include <string>

struct MyStruct
{
	int hoge;
};

void process(const MyStruct& lvalArg) {
	std::cout << "const T&" << std::endl;
}

void process(MyStruct&& lvalArg) {
	std::cout << "T&&" << std::endl;
}

template<typename T>
void logAndProcess(T&& param) {
	process(std::forward<T>(param));
}

int main() {
	MyStruct a;
	logAndProcess(a);
	logAndProcess(std::move(a));

	return 0;
}
