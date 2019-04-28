#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject* go)
    : owner(go)
{
}

Transform::Transform(GameObject * go)
    : Component(go)
{
}

void Transform::Update()
{
    printf("TR : %x ", (uint32_t)this);
}

Tag Transform::GetTag()
{
    return Tag::Transform;
}

Collision::Collision(GameObject * go)
    : Component(go)
{
}

void Collision::Update()
{
    const auto tr = dynamic_cast<Transform*>(owner->GetComponent(Tag::Transform));
    tr->pos;
    printf(" CL : %x(TGT TR=%x) ", (uint32_t)this, (uint32_t)tr);
}

Tag Collision::GetTag()
{
    return Tag::Collision;
}
