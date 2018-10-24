#include <iostream>
#include <memory>
#include <vector>


class Hoge;

std::vector<std::weak_ptr<Hoge>> wPtrs;

class Hoge : public std::enable_shared_from_this<Hoge>
{
public:
	Hoge() {}
	Hoge(int num) : m_num(num) {}
	~Hoge() {}


	void SetThis()
	{
		wPtrs.emplace_back(shared_from_this());
	}

	void Show()
	{
		std::cout << m_num << std::endl;
	}

	int m_num;
};


int main()
{
	std::vector<std::shared_ptr<Hoge>> sPtrs;
	for (int i = 0; i < 5; i++) {
		sPtrs.emplace_back(std::make_shared<Hoge>(i));
	}

	sPtrs[3]->SetThis();
	sPtrs[4]->SetThis();
	sPtrs[2]->SetThis();

	for (auto&& i : wPtrs) {
		if (auto r = i.lock()) {
			r->Show();
		}
	}


	return 0;
}
