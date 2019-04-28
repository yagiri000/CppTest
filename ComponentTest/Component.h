#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include "Tag.h"
#include <bitset>

class Transform;
class GameObject;

class Component
{
public:
    Component() = default;
    Component( GameObject* go );
    virtual ~Component() = default;
    virtual void Update() = 0;
    virtual ComponentType GetType() = 0;
    GameObject* owner;
};
