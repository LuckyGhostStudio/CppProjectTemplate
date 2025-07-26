#pragma once

namespace LFrame
{
    class Node;

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
       // Node* m_Owner;               // 所属节点
    };
}