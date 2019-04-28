#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include "Tag.h"

class Component;

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;
    std::vector<std::unique_ptr<Component>> components;

    void AddComponent(std::unique_ptr<Component>&& cmp);

    Component* GetComponent(Tag tag);

    void Update();
};