#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <stack>

#include "LFrame/Core/Object.h"

namespace LFrame
{
    /// <summary>
    /// 节点基类
    /// </summary>
    class GameObject : public Object
    {
    public:
        GameObject(const std::string& name);
        virtual ~GameObject();

        virtual bool AddChild(GameObject* child);
        virtual bool RemoveChild(GameObject* child);
        virtual void Delete();

        bool IsActive() const { return m_IsActive; }
        void SetActive(bool active) { m_IsActive = active; }

        GameObject* GetParent() const { return m_Parent; }
        const std::vector<GameObject*>& GetChildren() const { return m_Children; }
        uint32_t GetChildCount() const { return static_cast<uint32_t>(m_Children.size()); }
        GameObject* GetChild(uint32_t index) const;

        uint32_t GetLevel() const { return m_Level; }
        void SetLevel(uint32_t level) { m_Level = level; }

        bool IsLeaf() const { return m_Children.size() == 0; }
    protected:
        /// <summary>
        /// 深度优先遍历
        /// </summary>
        /// <param name="onVisitFunc">访问方法</param>
        template <typename VisitFunc>
        void DFS(VisitFunc onVisitFunc)
        {
            GameObject* root = this;  // 当前节点作为根节点

            std::unordered_set<GameObject*> visited;
            std::stack<GameObject*> stk;
            stk.push(root);

            while (!stk.empty())
            {
                GameObject* gameObject = stk.top();
                stk.pop();

                onVisitFunc(gameObject);  // 访问节点

                // 逆序
                for (int i = gameObject->GetChildCount() - 1; i >= 0; --i)
                {
                    // 未访问过的节点入栈
                    if (visited.find(gameObject->GetChild(i)) == visited.end())
                    {
                        stk.push(gameObject->GetChild(i));
                        visited.insert(gameObject->GetChild(i));
                    }
                }
            }
        }
    private:
        bool m_IsActive = true;                 // 启用状态
        GameObject* m_Parent = nullptr;         // 父节点
        std::vector<GameObject*> m_Children;    // 子节点列表

        uint32_t m_Level = 0;                   // 层级 从0开始

        friend class GameObjectUtility;
    };
}