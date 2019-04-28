#include "Component.h"
#include "GameObject.h"



Component::Component(GameObject* go)
    : owner(go)
{
}
