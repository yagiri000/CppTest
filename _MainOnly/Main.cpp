#include <iostream>
#include <vector>
#include <functional>


void Hoge()
{
	static constexpr float aaa = 2.0f;
	std::cout << aaa << std::endl;

}

int main()
{
	Hoge();

	return 0;
}