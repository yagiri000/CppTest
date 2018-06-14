#include <iostream>
#include <memory>
class Widget {
public:
	bool hoge()const {
		std::cout << "hoge called" << std::endl;
		return true;
	}
};


int main()
{
	auto pw = std::make_unique<Widget>();
	
	auto func = [pw_ = std::move(pw)]{
		return pw_->hoge();
	};

	return 0;
}