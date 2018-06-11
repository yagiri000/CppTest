#include <iostream>

// ���j���@�[�T���Q�Ƃ����I�[�o�[���[�h�������ׂ���
// �{�����l�^�͉��̃I�[�o�[���[�h���Ă΂�Ăق���

template <typename T>
void hoge(T&& val) {
	std::cout << "call void(T&&) func" << std::endl;
}

void hoge(int val) {
	std::cout << "call void(int) func" << std::endl;
}

int main()
{
	int intVal = 100;
	short shortVal = 100;
	hoge(intVal);
	hoge(shortVal);

	return 0;
}