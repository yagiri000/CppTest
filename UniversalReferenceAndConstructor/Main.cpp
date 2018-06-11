#include <iostream>
#include <string>

// ユニヴァーサル参照を取るオーバーロードを避けるべき例 コンストラクタ版
// Perfect forwardingコンストラクタを作るとコピーコンストラクタを呼ぼうとした際にも
// Perfect forwardingコンストラクタが呼ばれる


// 本来はインデックスに対応するstd::stringを返す関数
// (サンプルコードなので適当な文字列を返すようにした）
std::string nameFromIdx(int idx) {
	return "aaa";
}


class Person {
public:

	// 完   全   転   送 
	// Perfect forwarding コンストラクタ
	template<typename T>
	explicit Person(T&& n)
		: name(std::forward<T>(n)) {
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
	Person a(10);
	Person b(std::string("hoge"));


	// !!!!!!!!!!
	// コピーコンストラクタではなく完全転送コンストラクタを呼ぼうとするのでエラー
	Person cloneOfP(b);

	return 0;
}