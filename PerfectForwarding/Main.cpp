// Perfect Forwarding���o���Ȃ���ʂ̗�

#include <iostream>
#include <vector>


template<typename... Ts>
void fwd(Ts&&... params) {

}

struct IPv4Header {
	std::uint32_t version : 4,
		IHL : 4,
		DSCP : 6,
		ECN : 2,
		totalLength : 16;
};

int main()
{

	// �g���ʂɂ�鏉�����q�̎g�p�����S�]���ł��Ȃ���ނɊY�����邽�߃R���p�C���ł��Ȃ�
	//fwd({ 1, 2, 3 }); 
	auto a = { 1, 2, 3 };
	fwd(a);

	IPv4Header h;
	// ��const�ȃr�b�g�t�B�[���h���Q�Ƃɓn���Ȃ��̂ŃR���p�C���s�\
	//fwd(h.totalLength);
	auto length = static_cast<std::uint32_t>(h.totalLength);
	fwd(length);

	return 0;
}