#include <iostream>
#include <functional>


int main()
{
	auto f = []() {};

	auto direness = [](const auto &a, const auto &b) {
		return *a < *b;
	};


	return 0;
}