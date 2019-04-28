#pragma once
#include "Component.h"

class GameObject;

class Collision : public Component
{

private:
    using LayerType = uint16_t;
public:

    struct Layer
    {
        static const LayerType Default;
        static const LayerType PlayerAttack;
        static const LayerType Enemy;
        static const LayerType None;
    };

    Collision() = default;
    Collision(GameObject* go, const LayerType& layer);
    virtual ~Collision() = default;
    void Update() override;
    virtual ComponentType GetType() override;
    bool CheckHit(Collision* col);
    void OnCollision(GameObject* target);

private:
    LayerType m_Layer;
};
