#include "Object.h"

#include <iostream>
#include <sstream>

namespace LFrame
{
    Object::Object(const std::string& name)
        : m_Name(name)
    {

    }

    Object::~Object()
    {
        // 清理子节点
        for (Object* child : m_Children)
        {
            if (child)
            {
                child->m_Parent = nullptr;  // 清除父节点引用
                delete child;               // 删除子节点
            }
        }
    }

    bool Object::AddChild(Object* child)
    {
        if (!child)
        {
            std::cerr << "Invalid child object." << std::endl;
            return false;
        }

        // 子节点已经有父节点 先从原父节点中移除
        if (child->m_Parent)
        {
            child->m_Parent->RemoveChild(child);
        }

        // 设置父节点
        m_Children.push_back(child);
        child->m_Parent = this;
        child->m_Level = this->m_Level + 1;  // 设置子节点的层级

        return true;
    }

    bool Object::RemoveChild(Object* child)
    {
        if (!child)
        {
            std::cerr << "Invalid child object." << std::endl;
            return false;
        }

        // 查找并移除子节点
        auto it = std::find(m_Children.begin(), m_Children.end(), child);
        if (it == m_Children.end())
        {
            std::cerr << "Child object not found." << std::endl;
            return false;
        }
       
        (*it)->m_Parent = nullptr;  // 清除父节点引用
        m_Children.erase(it);       // 从子节点列表中移除
        child = nullptr;

        return true;
    }

    void Object::Delete()
    {
        if (m_Parent)
        {
            m_Parent->RemoveChild(this);  // 从父节点中移除自己
        }
    }

    Object* Object::GetChild(uint32_t index) const
    {
        if (index < 0 || index >= static_cast<uint32_t>(m_Children.size()))
        {
            std::cerr << "Index out of bounds." << std::endl;
            return nullptr;
        }

        return m_Children[index];
    }
}
