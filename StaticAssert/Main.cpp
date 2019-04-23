#include <iostream>
#include <vector>
#include <functional>


void Hoge()
{
	static constexpr float aaa = 2.0f;

}

int main()
{
	static_assert(true, "aaa");
	static_assert(false, "aaa");

	return 0;
}