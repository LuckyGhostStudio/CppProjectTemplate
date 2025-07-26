#pragma once

#include "LFrame/Core/Object.h"

namespace LFrame
{
    class GameObject;

    class Component : public Object
    {
    public:
        Component() : Object("Component") {}
        virtual ~Component() = default;

        GameObject* GetGameObject() const { return m_GameObject; }

        virtual void OnStart() {}
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void OnDestroy() {}
    protected:
        GameObject* m_GameObject = nullptr; // ËùÊôµÄGameObject

        friend class GameObject;
    };
}