#pragma once

#include <string>

namespace LFrame
{
    /// <summary>
    /// 对象基类
    /// </summary>
    class Object
    {
    public:
        Object(const std::string& name) : m_Name(name) {};
        virtual ~Object() = default;

        const std::string& GetName() const { return m_Name; }
        void SetName(const std::string& name) { m_Name = name; }
    protected:
        std::string m_Name; // 对象名称
    };
}