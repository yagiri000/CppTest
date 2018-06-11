#include "Widget.h"



Widget::Widget()
	:
	pImpl(std::make_unique<Impl>())
{
}

Widget::~Widget() = default;

struct Widget::Impl {
	int hoge;
	bool piyo;
};