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

	// �p�^�[��1 : �g���ʂň͂񂾏������q��initializer_list�Ƃ��Ď����I�ɐ��_�����@ex.auto�̌^���_
	// �p�^�[��2 : �g���ʂň͂񂾏������q��initializer_list�Ƃ��Ď����I�ɐ��_����Ȃ��@ex.�e���v���[�g�̌^���_�C�֐��̖߂�l�𐄘_���邽�߂�auto(�����̃e���v���[�g�j

	return 0;
}