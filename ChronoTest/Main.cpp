#include <iostream>
#include <functional>
#include <chrono>

bool is_pow2(unsigned num) {
	int count = 0;
	for (; num > 0; num >>= 1) {
		if ((num & 1) == 1) {
			if (count > 0) {
				return false;
			}
			else {
				count++;
			}
		}
	}
	return true;
}
bool is_pow2_closed(unsigned num) {
	return ((num != 0) && !(num & (num - 1)));
}


int main()
{
	constexpr int N = 1000 * 1000;

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			is_pow2(256);
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";

	}

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			is_pow2_closed(256);
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";

	}


	return 0;
}