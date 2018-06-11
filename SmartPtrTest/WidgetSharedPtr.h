#pragma once
#include <memory>

class WidgetSharedPtr {
public:
	WidgetSharedPtr();
	~WidgetSharedPtr();

private:
	struct Impl;
	std::unique_ptr<Impl> pImpl;
};