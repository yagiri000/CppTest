#include <iostream>
#include <string>

// ユニヴァーサル参照を取るオーバーロードでの問題を解決した例
// Perfect forwardingコンストラクタを作るとコピーコンストラクタを呼ぼうとした際にも
// Perfect forwardingコンストラクタが呼ばれる問題があったが，
// enable_ifを用いて条件分岐するようにし，問題を解決した
// また，汎整数型を取るコンストラクタもintegral_vを用いて正しく呼べるようにした


// 本来はインデックスに対応するstd::stringを返す関数
// (サンプルコードなので適当な文字列を返すようにした）
std::string nameFromIdx(int idx) {
	return "aaa";
}


class Person {
public:

	// 完   全   転   送 
	// Perfect forwarding コンストラクタ
	template<
		typename T,
		typename = std::enable_if_t<
		!std::is_base_of_v<Person, std::decay_t<T>	>
		&&
		!std::is_integral_v<std::remove_reference_t<T>>
		>
	>
	explicit Person(T&& n)
		: name(std::forward<T>(n)) {
		static_assert(
			std::is_constructible_v<std::string, T>,
			"Parameter n can't be used to costruct a std::string"
			);
		std::cout << "call constructor(T&&)" << std::endl;
	}

	explicit Person(int idx)
		: name(nameFromIdx(idx)) {
		std::cout << "call constructor(int)" << std::endl;
	}

private:
	std::string name;
};

int main()
{
	short shortVal = 10;
	Person a(shortVal);
	Person b("hoge");
	// Person c(u"hoge");


	Person cloneOfP(b);

	return 0;
}