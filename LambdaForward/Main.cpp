// auto&& ‰¼ˆø”‚ğstd::forward ‚·‚éê‡‚Ídecltype ‚ğ—p‚¢‚é

#include <iostream>
#include <chrono>>

class Vec2{};

int normalize(int x) {
	std::cout << "called normalize(int)" << std::endl;
	return x;
}

Vec2 normalize(Vec2 x) {
	std::cout << "called normalize(Vec2)" << std::endl;
	return x;
}



int main() {
	auto f = [](auto&& x) {
		return normalize(std::forward<decltype(x)>(x));
	};

	f(10);
	f(10.0);
	f(Vec2());


	return 0;
}