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

    // []演算子で見るだけで作成される
    dic["aaa"];
    
    // atで存在しない要素を見るとエラー
    // コメントを外すとエラー
    // dic.at("bbb");

    show();

    return 0;
}