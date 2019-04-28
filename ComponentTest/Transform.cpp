#include "Transform.h"

Transform::Transform( GameObject * go )
    : Component( go )
{
}

void Transform::Update()
{
    printf( "TR : %x ", (uint32_t)this );
}

ComponentType Transform::GetType()
{
    return ComponentType::Transform;
}
