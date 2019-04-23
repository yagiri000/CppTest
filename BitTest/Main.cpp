#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <array>

enum class Buttons
{
	A = 1,
	B = 1 << 1,
	C = 1 << 2,
	D = 1 << 3,
	CorD = C | D
};

using BitType = unsigned int;

BitType state;

bool GetButton(Buttons button)
{
	return state & (BitType)button;
}

int main()
{
	std::cout << (size_t)Buttons::A << std::endl;
	std::cout << (size_t)Buttons::B << std::endl;
	std::cout << (size_t)Buttons::C << std::endl;
	std::cout << (size_t)Buttons::CorD << std::endl;

	state = 0;
	std::cout << GetButton(Buttons::C) << std::endl;

	std::cout << std::endl;

	for (size_t i = 0; i < 13; i++) {
		state = i;
		std::cout << GetButton(Buttons::C) << " ";
	}


	std::cout << std::endl;

	for (size_t i = 0; i < 13; i++) {
		state = i;
		std::cout << GetButton(Buttons::CorD) << " ";
	}

	std::cout << std::endl;

	return 0;
}