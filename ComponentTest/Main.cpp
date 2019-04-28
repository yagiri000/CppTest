#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>

#include "GameObject.h"
#include "Component.h"

int main()
{
    std::vector<std::unique_ptr<GameObject>> objs;
    for (size_t i = 0; i < 3; i++)
    {
        auto obj(std::make_unique<GameObject>());
        obj->AddComponent(std::make_unique<Transform>(obj.get()));
        obj->AddComponent(std::make_unique<Collision>(obj.get()));
        objs.emplace_back(std::move(obj));
    }

    for (auto&& i : objs)
    {
        i->Update();
    }


    return 0;
}