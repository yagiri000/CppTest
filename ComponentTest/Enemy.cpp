#include "Enemy.h"
#include "Component.h"
#include "Collision.h"
#include "Transform.h"



Enemy::Enemy()
{
    AddComponent(std::make_unique<Collision>(this, Collision::Layer::Enemy));
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
    GameObject::Update();
    printf("(Enemy)", (uint32_t)this);
}
