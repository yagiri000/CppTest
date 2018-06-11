#include "WidgetSharedPtr.h"



WidgetSharedPtr::WidgetSharedPtr()
	:
	pImpl(std::make_unique<Impl>())
{
}

WidgetSharedPtr::~WidgetSharedPtr() = default;

struct WidgetSharedPtr::Impl {
	int hoge;
	bool piyo;
};