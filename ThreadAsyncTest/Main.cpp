#include <iostream>
#include <thread>
#include <future>


void main() {
	constexpr int N = 1e3;

	{
		auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�
		for (int i = 0; i < N; i++) {
			std::thread t;
			t = std::thread([]() { return; });
			t.join();
		}
		auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
		std::cout << msec << " milli sec \n";
	}

	{
		auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�
		for (int i = 0; i < N; i++) {
			std::async(std::launch::async, []() { return; });
		}
		auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();	// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
		std::cout << msec << " milli sec \n";
	}
}