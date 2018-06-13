// Perfect Forwardingが出来ない場面の例

#include <iostream>
#include <vector>


template<typename... Ts>
void fwd(Ts&&... params) {

}

struct IPv4Header {
	std::uint32_t version : 4,
		IHL : 4,
		DSCP : 6,
		ECN : 2,
		totalLength : 16;
};

int main()
{

	// 波括弧による初期化子の使用が完全転送できない種類に該当するためコンパイルできない
	//fwd({ 1, 2, 3 }); 
	auto a = { 1, 2, 3 };
	fwd(a);

	IPv4Header h;
	// 非constなビットフィールドを参照に渡せないのでコンパイル不能
	//fwd(h.totalLength);
	auto length = static_cast<std::uint32_t>(h.totalLength);
	fwd(length);

	return 0;
}