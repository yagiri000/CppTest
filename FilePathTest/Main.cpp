#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

int main()
{
	std::ifstream ifs("test.txt");
	if (ifs.fail()) {
		std::cerr << "Ž¸”s" << std::endl;
		return -1;
	}
	std::string str((std::istreambuf_iterator<char>(ifs)),
		std::istreambuf_iterator<char>());
	std::cout << "[" << str << "]" << std::endl;
	return 0;
}