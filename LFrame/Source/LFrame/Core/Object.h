#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <stack>

namespace LFrame
{
    /// <summary>
    /// 节点基类
    /// </summary>
    class Object
    {
    public:
        friend class ObjectUtility;
    public:
        explicit Object(const std::string& name);
        virtual ~Object();

        // 禁止拷贝和赋值（节点树结构应该唯一）
        Object(const Object&) = delete;
        Object& operator=(const Object&) = delete;

        virtual bool AddChild(Object* child);
        virtual bool RemoveChild(Object* child);
        virtual void Delete();

        //// 节点遍历方法
        //Node* FindChildByName(const std::string& name) const;
        //std::vector<Node*> FindChildrenByName(const std::string& name) const;

        // Getters/Setters
        const std::string& GetName() const { return m_Name; }
        void SetName(const std::string& name) { m_Name = name; }

        bool IsActive() const { return m_Enable; }
        void SetActive(bool active) { m_Enable = active; }

        Object* GetParent() const { return m_Parent; }
        const std::vector<Object*>& GetChildren() const { return m_Children; }
        uint32_t GetChildCount() const { return static_cast<uint32_t>(m_Children.size()); }
        Object* GetChild(uint32_t index) const;

        uint32_t GetLevel() const { return m_Level; }
        void SetLevel(uint32_t level) { m_Level = level; }

        bool IsLeaf() const { return m_Children.size() == 0; }
    protected:
        /// <summary>
        /// 深度优先遍历
        /// </summary>
        /// <param name="onVisitObjectFunc">节点访问方法</param>
        template <typename VisitFunc>
        void DFS(VisitFunc onVisitObjectFunc)
        {
            Object* root = this;  // 当前节点作为根节点

            std::unordered_set<Object*> visited;
            std::stack<Object*> stk;
            stk.push(root);

            while (!stk.empty())
            {
                Object* object = stk.top();
                stk.pop();

                onVisitObjectFunc(object);    // 访问节点

                // 逆序
                for (int i = object->GetChildCount() - 1; i >= 0; --i)
                {
                    // 未访问过的节点入栈
                    if (visited.find(object->GetChild(i)) == visited.end())
                    {
                        stk.push(object->GetChild(i));
                        visited.insert(object->GetChild(i));
                    }
                }
            }
        }
    protected:
        std::string m_Name;             // 节点名称
        bool m_Enable = true;           // 启用状态
        Object* m_Parent = nullptr;       // 父节点
        std::vector<Object*> m_Children;  // 子节点列表

        uint32_t m_Level = 0;           // 节点层级 从0开始
    };
}