#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include "Tag.h"

class Transform;
class GameObject;

struct Vec3
{
    float x, y, z;
};

class Component
{
public:
    Component() = default;
    Component(GameObject* go);
    virtual ~Component() = default;
    virtual void Update() = 0;
    virtual Tag GetTag() = 0;
    GameObject* owner;
};

class Transform : public Component
{
public:
    Vec3 pos;

    Transform() = default;
    Transform(GameObject* go);
    virtual ~Transform() = default;
    void Update() override;
    virtual Tag GetTag() override;
};

class Collision : public Component
{
public:

    Collision() = default;
    Collision(GameObject* go);
    virtual ~Collision() = default;
    void Update() override;
    virtual Tag GetTag() override;
};
