#include <iostream>
#include <thread>
#include <future>


void main() {
	constexpr int N = 1e3;

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			std::thread t;
			t = std::thread([]() { return; });
			t.join();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";
	}

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			std::async(std::launch::async, []() { return; });
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";
	}
}