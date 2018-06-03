#include <iostream>


template<typename T>
void f_ref(T& param) {}

template<typename T>
void f_const_ref(const T& param) {}

template<typename T>
void f_ptr(T* param) {}

template<typename T>
void f_uniref(T&& param) {}

template<typename T>
void f_by_val(T param) {}

void myFunc(int Param[]) {}
void myFunc_(int *Param) {}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept
{
	return N;
}

void someFunc(int, double) {}

int main()
{
	int x = 27;
	const int cx = x;
	const int &rx = x;

	f_ref(x);
	f_ref(cx);
	f_ref(rx);

	f_const_ref(x);
	f_const_ref(cx);
	f_const_ref(rx);

	const int *px = &x;
	f_ptr(&x);
	f_ptr(px);

	f_uniref(x);
	f_uniref(cx);
	f_uniref(rx);
	f_uniref(27);

	f_by_val(x);
	f_by_val(cx);
	f_by_val(rx);

	const char* const ptr = "Fun with poiters";
	f_by_val(ptr);

	const char name[] = "J. P. Briggs";
	const char * ptrToName = name;

	f_by_val(name);
	f_by_val(ptrToName);

	f_ref(name);

	constexpr auto size = arraySize(name);

	f_by_val(someFunc);

	f_ref(someFunc);



	return 0;
}