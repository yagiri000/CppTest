#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>

#include "GameObject.h"
#include "Component.h"
#include "Collision.h"
#include "Transform.h"

#include "Bullet.h"
#include "Enemy.h"

int main()
{
    std::vector<std::unique_ptr<GameObject>> objs;
    for (size_t i = 0; i < 2; i++)
    {
        auto obj(std::make_unique<GameObject>());
        obj->AddComponent(std::make_unique<Transform>(obj.get()));
        obj->AddComponent(std::make_unique<Collision>(obj.get(), Collision::Layer::None));
        objs.emplace_back(std::move(obj));
    }

    objs.emplace_back(std::make_unique<Enemy>());
    objs.emplace_back(std::make_unique<Bullet>());


    for (auto&& i : objs)
    {
        i->Update();
    }

    // ƒRƒŠƒWƒ‡ƒ“
    for (size_t i = 0; i < objs.size(); i++)
    {
        for (size_t j = i + 1; j < objs.size(); j++)
        {
            auto a = objs[i]->GetComponent<Collision>(ComponentType::Collision);
            auto b = objs[j]->GetComponent<Collision>(ComponentType::Collision);
            if (a != nullptr && b != nullptr)
            {
                if (a->CheckHit(b))
                {
                    a->OnCollision(objs[j].get());
                    b->OnCollision(objs[i].get());
                }
            }
        }
    }
    

    return 0;
}