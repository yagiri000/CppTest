#include <iostream>

#include <mutex>
#include <vector>

class Polynomial {
public:
	using RootsType = std::vector<double>;

	RootsType roots() const
	{
		std::lock_guard<std::mutex> g(m);  // lock mutex

		if (!rootsAreValid) {              // if cache not valid

										   // ...                           // compute roots here

			rootsAreValid = true;
		}                                  // release mutex

		return rootVals;
	}


private:
	mutable std::mutex m;
	mutable bool rootsAreValid{ false };
	mutable RootsType rootVals{};
};

void main() {
	Polynomial a;
	// Polynomial b = a;
	// Polynomial c = std::move(a);
}