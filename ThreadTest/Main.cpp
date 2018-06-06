#include <iostream>
#include <thread>
#include <future>

void f1(int n) {
	std::cout << "thread " << n << std::endl;
}

void promise_future_example() {
	auto meaning = [](std::promise<int>& prom) {
		prom.set_value(42); // ������meaning ���v�Z
	};
	std::promise<int> prom;
	std::thread(meaning, std::ref(prom)).detach();
	std::future<int> result = prom.get_future();
	std::cout << "the meaning of life: " << result.get() << "\n";
}

void main() {
	std::thread t1; // �X���b�h�ϐ��A�X���b�h�ł͂Ȃ�
	t1 = std::thread(f1, 1); // �X���b�h�ϐ��ɃX���b�h����
	t1.join(); // �X���b�h�̊�����҂�
	std::thread t2(f1, 2);
	std::thread t3(std::move(t2));
	std::thread t4([]() { return; });// �����_���ł����܂�����
	t4.detach();
	t3.join();
	promise_future_example();
}