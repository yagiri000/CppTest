#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <array>

int main()
{
	constexpr size_t N = 10000;
	constexpr size_t M = 10000;
	std::vector<int> arr;
	arr.resize(N);
	std::vector<int> arr2;
	arr2.resize(M);
	std::vector<int> result;
	result.resize(N*M);

	{
		for (size_t i = 0; i < N; i++) {
			arr[i] = rand();
		}
		for (size_t i = 0; i < M; i++) {
			arr2[i] = rand();
		}
		auto start = std::chrono::system_clock::now();      // �v���X�^�[�g������ۑ�

		size_t count = 0;
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				result[count] = arr[i] + arr2[j];
				count++;
			}
		}
		auto end = std::chrono::system_clock::now();       // �v���I��������ۑ�
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// �v�������Ԃ��~���b�i1/1000�b�j�ɕϊ����ĕ\��
		std::cout << msec << " milli sec \n";

	}


	std::cout << " milli sec \n";

	return 0;
}