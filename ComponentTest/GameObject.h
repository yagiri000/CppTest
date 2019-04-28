#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include <unordered_map>
#include "Tag.h"

class Component;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject() = default;

    void AddComponent(std::unique_ptr<Component>&& cmp);
    template <typename T>
    T* GetComponent(ComponentType tag)
    {
        auto iter = m_Components.find(tag);
        if (iter != m_Components.end())
        {
            return dynamic_cast<T*>( iter->second.get());
        }

        return nullptr;
    }

    virtual void Update();

private:
    std::unordered_map<ComponentType, std::unique_ptr<Component>> m_Components;
};