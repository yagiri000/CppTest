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
		auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�
		for (int i = 0; i < N; i++) {
			is_pow2(256);
		}
		auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
		std::cout << msec << " milli sec \n";

	}

	{
		auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�
		for (int i = 0; i < N; i++) {
			is_pow2_closed(256);
		}
		auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
		std::cout << msec << " milli sec \n";

	}


	return 0;
}