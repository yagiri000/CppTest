#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Collision.h"

GameObject::GameObject()
{
    AddComponent(std::make_unique<Transform>());
}

void GameObject::AddComponent(std::unique_ptr<Component>&& cmp)
{
    m_Components.emplace(cmp->GetType(), std::move(cmp));
}

void GameObject::Update()
{
    printf("\nGO : %x ", (uint32_t)this);
    for (auto&& i : m_Components)
    {
        i.second->Update();
    }
}
