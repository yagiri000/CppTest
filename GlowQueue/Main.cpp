#include <iostream>
#include <vector>
#include <functional>
#include <memory>


template <typename T>
class GlowQueue
{
public:
	GlowQueue() :
		count(0)
	{
		vec.resize(FirstSize);
	}

	~GlowQueue()
	{
	}

	void Emplace(T obj)
	{
		if (!(count < vec.size())) {
			vec.resize(vec.size() * 2);
		}
		vec[count] = obj;
		count++;
	}

	void Flush()
	{
		for (size_t i = 0; i < count; i++) {
			std::cout << i << std::endl;
		}
		std::cout << "size:" << vec.size() << std::endl;
		std::cout << "count:" << count << std::endl;
		count = 0;
	}

private:
	size_t count;
	static constexpr size_t FirstSize = 2;
	std::vector<T> vec;
};





int main()
{

	GlowQueue<size_t> queue;
	for (size_t i = 0; i < 20; i++) {
		queue.Emplace(i);
	}

	queue.Flush();

	

	return 0;
}