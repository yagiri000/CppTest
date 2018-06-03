#include <iostream>
#include <vector>
#include <string>

template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
{
	return c[i];
}

template<typename Container, typename Index>
decltype(auto) authAndAccessDeclAuto(Container&& c, Index i)
{
	return std::forward<Container>(c)[i];
}

std::vector<std::string> makeStringVector() {
	std::vector<std::string> a;
	return a;
}

decltype(auto) f1() {
	int x = 0;
	return x;
}

decltype(auto) f2() {
	int x = 0;
	return (x);
}


int main()
{
	const int i = 0;
	decltype(i) hoge = 20.0;
	std::vector<std::string> v;
	authAndAccess(v, 10);
	authAndAccessDeclAuto(v, 10) = 99;
	auto str = authAndAccessDeclAuto(makeStringVector(), 10);

	return 0;
}