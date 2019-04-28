#include "GameObject.h"
#include "Collision.h"
#include "Transform.h"

const Collision::LayerType Collision::Layer::Default(0b1111);
const Collision::LayerType Collision::Layer::PlayerAttack(0b0010);
const Collision::LayerType Collision::Layer::Enemy(0b0010);
const Collision::LayerType Collision::Layer::None(0b0000);


Collision::Collision(GameObject * go, const LayerType & layer)
    : Component(go)
    , m_Layer(layer)
{
}

void Collision::Update()
{
    const auto tr = owner->GetComponent<Transform>(ComponentType::Transform);
    tr->pos;
    printf(" CL : %x(TGT-TR=%x) ", (uint32_t)this, (uint32_t)tr);
}

ComponentType Collision::GetType()
{
    return ComponentType::Collision;
}

bool Collision::CheckHit(Collision * col)
{
    // FIXME

    // ƒŒƒCƒ„[‚ªŒð‚í‚ç‚È‚¢‚à‚Ì‚¾‚Á‚½‚çfalse
    if (!(m_Layer & col->m_Layer))
    {
        return false;
    }
    return true;
}

void Collision::OnCollision(GameObject * target)
{
    auto a = owner->GetComponent<Collision>(ComponentType::Collision);
    auto b = target->GetComponent<Collision>(ComponentType::Collision);
    printf("\nCollision : %x & %x (Layer:%x, %x) ", (uint32_t)owner, (uint32_t)target, a->m_Layer, b->m_Layer);
    //owner->OnCollision(target);
}
