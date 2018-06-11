#include <iostream>
#include <memory>
#include "Widget.h"

// Widgetのデストラクタを書かないとコンパイルエラー「認識できない型Widget::Implが使われています。」が出る例
// （書いているので通る）


int main() {
	Widget a;

	return 0;
}
