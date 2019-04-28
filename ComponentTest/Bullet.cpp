#include "Bullet.h"
#include "Component.h"
#include "Collision.h"
#include "Transform.h"



Bullet::Bullet()
{
    AddComponent(std::make_unique<Collision>(this, Collision::Layer::PlayerAttack));
}

void Bullet::Update()
{
    GameObject::Update();
    printf("(Bullet)", (uint32_t)this);
}

