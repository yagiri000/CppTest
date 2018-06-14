#include <iostream>
#include <vector>
#include <functional>
#include <memory>

// �X�R�[�v����������divisor���X�R�[�v����O��ď�������s���ɂȂ��B
// �R���p�C���͒ʂ邵�ꍇ�ɂ���Ă͖��Ȃ�����
// �R���p�C���͒ʂ邵�ꍇ�ɂ���Ă͖��Ȃ�����

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
	// s_Divisor��static�Ȃ̂ŉ����L���v�`�����Ă��Ȃ��B
	filters.emplace_back(
		[=](int value) {return value % s_Divisor == 0; }
	);
	// ���Ɠ���
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