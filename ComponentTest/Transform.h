#pragma once
#include "Component.h"

class GameObject;

struct Vec3
{
    float x, y, z;
};


class Transform : public Component
{
public:
    Vec3 pos;

    Transform() = default;
    Transform(GameObject* go);
    virtual ~Transform() = default;
    void Update() override;
    virtual ComponentType GetType() override;
};
