#include <iostream>
#include <vector>
#include <memory>

enum class Type
{
    A,
    B
};

class Base
{

};

class A : public Base
{
public:
    static constexpr Type GetType()
    {
        return Type::A;
    }
};

class B : public Base
{
public:
    static constexpr Type GetType()
    {
        return Type::B;
    }

};


std::vector<std::unique_ptr<Base>> vec;

template <typename T>
T* GetComponent()
{
    for (auto&& i : vec)
    {
        if(i->Type == T::GetType)
        {
            retu
    }
}

int main()
{

    


    return 0;
}