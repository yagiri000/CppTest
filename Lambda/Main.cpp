#include <iostream>
#include <vector>
#include <functional>
#include <memory>

// スコープ抜けた時にdivisorがスコープから外れて消去され不正になる例達
// コンパイルは通るし場合によっては問題なく動く
// コンパイルは通るし場合によっては問題なく動く

std::vector<std::function<bool(int)>> filters;

void setFunc() {
	auto divisor = 5;
	static auto s_Divisor = 10;
	filters.emplace_back(
		[&](int value) {return value % divisor == 0; }
	);
	filters.emplace_back(
		[&divisor](int value) {return value % divisor == 0; }
	);
	filters.emplace_back(
		[=](int value) {return value % divisor == 0; }
	);
	// s_Divisorはstaticなので何もキャプチャしていない。
	filters.emplace_back(
		[=](int value) {return value % s_Divisor == 0; }
	);
	// 一個上と同じ
	filters.emplace_back(
		[](int value) {return value % s_Divisor == 0; }
	);
}


class Widget {
public:
	void addFilter() {
		filters.emplace_back(
			[=](int value) {
			return value % divisor == 0;
		}
		);

		filters.emplace_back(
			[divisor = divisor](int value) {
			return value % divisor == 0;
		}
		);

	}

private:
	int divisor = 4;
};




int main()
{
	setFunc();
	{
		std::unique_ptr<Widget> a = std::make_unique<Widget>();
		a->addFilter();
	}
	filters[0](10);
	filters[1](10);
	filters[2](10);
	filters[3](10);

	return 0;
}