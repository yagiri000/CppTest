#include <iostream>
#include <vector>


void main() {
	std::vector<int> v;
	
	for (int i = 0; i < 10; i++) {
		v.emplace_back(i);
	}

	for (auto i = v.begin(); i < v.end(); i++) {
		//*i *= 2;
	}

}