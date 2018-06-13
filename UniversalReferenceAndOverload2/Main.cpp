#include <iostream>
#include <string>

// ユニヴァーサル参照を取るオーバーロードをタグディスパッチを用いて実装する例

template <typename T>
void hoge(T&& val) {
	std::cout << "called func hoge" << std::endl;
	hogeImpl(
		std::forward<T>(val), 
		std::is_integral<std::remove_reference_t<T>>()
	);
}

template <typename T>
void hogeImpl(T val, std::true_type) {
	std::cout << "called void(T, true_type) impl" << std::endl;
	std::cout << "val : " << val << std::endl;
}

template <typename T>
void hogeImpl(T val, std::false_type) {
	std::cout << "called void(T, false_type) impl" << std::endl;
	std::cout << "val : " << val << std::endl;
}

int main()
{
	short shortVal = 100;
	std::string stringVal("aaa");
	hoge(shortVal);
	hoge(stringVal);

	return 0;
}