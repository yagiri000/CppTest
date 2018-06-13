#include <iostream>
#include <array>
class Widget {

};

Widget widgetFactory() {
	return Widget();
}


template<typename T>
void func(T&& param) {

}

template <typename T>
class Hoge {
public:
	typedef T&& RvalueRefToT;
};

int main()
{
	Widget w;
	func(w);
	func(widgetFactory());
	func(Widget());

	int x;
	auto&& rx = x;


	Hoge<int&> hoge;
	Hoge<int&>::RvalueRefToT;
	return 0;
}