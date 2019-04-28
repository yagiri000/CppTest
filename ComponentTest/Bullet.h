#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
public:
    Bullet();
    virtual ~Bullet() = default;
    void Update() override;
};

