#include "Component.h"
#include "GameObject.h"

void GameObject::AddComponent(std::unique_ptr<Component>&& cmp)
{
    components.emplace_back(std::move(cmp));
}

Component* GameObject::GetComponent(Tag tag)
{
    for (auto i = components.begin(); i < components.end(); i++)
    {
        if ((*i)->GetTag() == tag)
        {
            return i->get();
        }
    }
    return nullptr;
}

void GameObject::Update()
{
    printf("GO : %x ", (uint32_t)this);
    for (auto&& i : components)
    {
        i->Update();
    }
    printf("\n");
}
