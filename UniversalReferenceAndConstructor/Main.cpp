#include <iostream>
#include <string>

// ���j���@�[�T���Q�Ƃ����I�[�o�[���[�h�������ׂ��� �R���X�g���N�^��
// Perfect forwarding�R���X�g���N�^�����ƃR�s�[�R���X�g���N�^���Ăڂ��Ƃ����ۂɂ�
// Perfect forwarding�R���X�g���N�^���Ă΂��


// �{���̓C���f�b�N�X�ɑΉ�����std::string��Ԃ��֐�
// (�T���v���R�[�h�Ȃ̂œK���ȕ������Ԃ��悤�ɂ����j
std::string nameFromIdx(int idx) {
	return "aaa";
}


class Person {
public:

	// ��   �S   �]   �� 
	// Perfect forwarding �R���X�g���N�^
	template<typename T>
	explicit Person(T&& n)
		: name(std::forward<T>(n)) {
		std::cout << "call constructor(T&&)" << std::endl;
	}

	explicit Person(int idx)
		: name(nameFromIdx(idx)) {
		std::cout << "call constructor(int)" << std::endl;
	}

private:
	std::string name;
};

int main()
{
	Person a(10);
	Person b(std::string("hoge"));


	// !!!!!!!!!!
	// �R�s�[�R���X�g���N�^�ł͂Ȃ����S�]���R���X�g���N�^���Ăڂ��Ƃ���̂ŃG���[
	Person cloneOfP(b);

	return 0;
}