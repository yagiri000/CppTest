#include <iostream>
#include <string>

// ���j���@�[�T���Q�Ƃ����I�[�o�[���[�h�ł̖�������������
// Perfect forwarding�R���X�g���N�^�����ƃR�s�[�R���X�g���N�^���Ăڂ��Ƃ����ۂɂ�
// Perfect forwarding�R���X�g���N�^���Ă΂���肪���������C
// enable_if��p���ď������򂷂�悤�ɂ��C������������
// �܂��C�Đ����^�����R���X�g���N�^��integral_v��p���Đ������Ăׂ�悤�ɂ���


// �{���̓C���f�b�N�X�ɑΉ�����std::string��Ԃ��֐�
// (�T���v���R�[�h�Ȃ̂œK���ȕ������Ԃ��悤�ɂ����j
std::string nameFromIdx(int idx) {
	return "aaa";
}


class Person {
public:

	// ��   �S   �]   �� 
	// Perfect forwarding �R���X�g���N�^
	template<
		typename T,
		typename = std::enable_if_t<
		!std::is_base_of_v<Person, std::decay_t<T>	>
		&&
		!std::is_integral_v<std::remove_reference_t<T>>
		>
	>
	explicit Person(T&& n)
		: name(std::forward<T>(n)) {
		static_assert(
			std::is_constructible_v<std::string, T>,
			"Parameter n can't be used to costruct a std::string"
			);
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
	short shortVal = 10;
	Person a(shortVal);
	Person b("hoge");
	// Person c(u"hoge");


	Person cloneOfP(b);

	return 0;
}