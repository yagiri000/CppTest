#include <iostream>
#include <thread>
#include <future>

void f1(int n) {
	std::cout << "thread " << n << std::endl;
}

void promise_future_example() {
	auto meaning = [](std::promise<int>& prom) {
		prom.set_value(42); // 生存のmeaning を計算
	};
	std::promise<int> prom;
	std::thread(meaning, std::ref(prom)).detach();
	std::future<int> result = prom.get_future();
	std::cout << "the meaning of life: " << result.get() << "\n";
}

void main() {
	std::thread t1; // スレッド変数、スレッドではない
	t1 = std::thread(f1, 1); // スレッド変数にスレッドを代入
	t1.join(); // スレッドの完了を待つ
	std::thread t2(f1, 2);
	std::thread t3(std::move(t2));
	std::thread t4([]() { return; });// ラムダ式でもうまくいく
	t4.detach();
	t3.join();
	promise_future_example();
}