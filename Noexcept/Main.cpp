#include <iostream>

void hoge() noexcept 
{
	std::cout << "aaa" << std::endl;
}



void main() {
	hoge();
}