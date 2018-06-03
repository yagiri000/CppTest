#include <iostream>
#include <vector>


void someFunc(int, double) {}

template <typename T>
void func(T param) {}

template <typename T>
void func_ini_list(std::initializer_list<T> param) {}

//auto createInitList() {
//	return { 1, 2, 3 };
//}



int main()
{
	auto x = 27;
	const auto cx = x;
	const auto& rx = x;

	auto&& uref1 = x;
	auto&& uref2 = cx;
	auto&& uref3 = 27;

	const char name[] = "R. N. Briggs";
	auto arr1 = name;
	auto& arr2 = name;

	auto func1 = someFunc;
	auto& func2 = someFunc;

	auto x1 = 27;
	auto x2(27);
	auto x3 = { 27 };
	auto x4{ 27 };


	auto hoge = { 1, 2, 3 };

	std::vector<int> vec;

	// func({ 1, 2, 3 });
	func_ini_list({ 1, 2, 3 });

	std::vector<int> v;
	auto resetV =
		[&v](const auto& newValue) {v = newValue; };

	// resetV({ 1, 2, 3 });

	// パターン1 : 波括弧で囲んだ初期化子をinitializer_listとして自動的に推論される　ex.autoの型推論
	// パターン2 : 波括弧で囲んだ初期化子をinitializer_listとして自動的に推論されない　ex.テンプレートの型推論，関数の戻り値を推論するためのauto(実質のテンプレート）

	return 0;
}