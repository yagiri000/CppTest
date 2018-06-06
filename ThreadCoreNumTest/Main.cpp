#include <iostream>
#include <thread>
#include <future>


int fibonacci(int x) {
	if (x == 0) {
		return 0;
	}
	else if (x == 1) {
		return 1;
	}
	else {
		return fibonacci(x - 1) + fibonacci(x - 2);
	}
}

void timewaster(unsigned iterations) {
	for (size_t i = 0; i < iterations; ++i) {
		fibonacci(iterations);
	}
}

void multithreaded_timewaster(
	unsigned iterations,
	unsigned threads) {
	std::vector<std::thread> t;
	t.reserve(threads);
	for (unsigned i = 0; i < threads; ++i) {
		t.push_back(std::thread(timewaster, iterations/threads));
	}
	for (unsigned i = 0; i < threads; ++i) {
		t[i].join();
	}
}

void main() {
	constexpr int N = 50;

	std::cout << std::thread::hardware_concurrency() << std::endl;

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		multithreaded_timewaster(N, 8);
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";
	}

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		multithreaded_timewaster(N, 4);
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";
	}

	{
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		multithreaded_timewaster(N, 2);
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec \n";
	}

}