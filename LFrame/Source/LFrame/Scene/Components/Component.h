#pragma once

namespace LFrame
{
    class GameObject;

    /// <summary>
    /// 组件基类
    /// </summary>
    class Component
    {
    public:
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void OnGUI() = 0;
    private:
        GameObject* m_GameObject;   // 所属节点
    };
}