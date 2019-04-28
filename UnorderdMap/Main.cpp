#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include <unordered_map>

int main()
{

    std::unordered_map<std::string, uint32_t> dic;
    const auto show = [&]()
    {
        for (auto&& i : dic)
        {
            std::cout << i.first << " " << i.second << std::endl;
        }
    };

    // []���Z�q�Ō��邾���ō쐬�����
    dic["aaa"];
    
    // at�ő��݂��Ȃ��v�f������ƃG���[
    // �R�����g���O���ƃG���[
    // dic.at("bbb");

    show();

    return 0;
}