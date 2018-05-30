#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>


class Base
{
public:
	virtual void f()
	{
		std::cout << "called Base f" << std::endl;
	}
};

class DerivedA : public Base
{
public:
	virtual void f()
	{
		std::cout << "called DerivedA f" << std::endl;
	}

	void AOrig()
	{
		std::cout << "called DerivedA AOrig" << std::endl;
	}
};

class DerivedB : public Base
{
public:
	virtual void f()
	{
		std::cout << "called DerivedB f" << std::endl;
	}
	void BOrig()
	{
		std::cout << "called DerivedA BOrig" << std::endl;
	}
};

int main()
{
	Base* da = new DerivedA();
	
	DerivedA* da_ = dynamic_cast<DerivedA*>(da);

	da_->AOrig();

	return 0;
}