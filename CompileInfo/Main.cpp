#include <iostream>

template<typename T>
class TD;

int main()
{
	int x = 10;
	TD<decltype(x)> xtype;

	return 0;
}