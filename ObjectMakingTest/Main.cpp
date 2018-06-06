#include <iostream>


class Hoge {
public:
	void Out() {
		std::cout << "aaa" << std::endl;
	}
};

void main() {
	auto x(0);
	auto y = 0;
	auto z{ 0 };
	auto w = { 0 };

	// Hoge h1();
	Hoge h1{};
	h1.Out();

}