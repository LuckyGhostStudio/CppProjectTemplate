#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <stack>

#include "LFrame/Components/Component.h"

#include "LFrame/Utilities/NodeUtility.h"

namespace LFrame
{
    /// <summary>
    /// 节点基类
    /// </summary>
    class Node
    {
    public:
        friend class NodeUtility;
    public:
        explicit Node(const std::string& name);
        virtual ~Node();

        // 禁止拷贝和赋值（节点树结构应该唯一）
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;

        virtual bool AddChild(Node* child);
        virtual bool RemoveChild(Node* child);
        virtual void Delete();

        //// 节点遍历方法
        //Node* FindChildByName(const std::string& name) const;
        //std::vector<Node*> FindChildrenByName(const std::string& name) const;

        virtual std::string ToString() const;

        // Getters/Setters
        const std::string& GetName() const { return m_Name; }
        void SetName(const std::string& name) { m_Name = name; }

        bool IsActive() const { return m_Enable; }
        void SetActive(bool active) { m_Enable = active; }

        Node* GetParent() const { return m_Parent; }
        const std::vector<Node*>& GetChildren() const { return m_Children; }
        size_t GetChildCount() const { return m_Children.size(); }
        Node* GetChild(int index) const;

        uint32_t GetLevel() const { return m_Level; }
        void SetLevel(uint32_t level) { m_Level = level; }

        bool IsLeaf() const { return m_Children.size() == 0; }
    protected:
        /// <summary>
        /// 深度优先遍历
        /// </summary>
        /// <param name="visitNodeFunc">节点访问方法</param>
        template <typename VisitFunc>
        void DFS(VisitFunc onVisitNodeFunc)
        {
            Node* root = this;  // 当前节点作为根节点

            std::unordered_set<Node*> visited;
            std::stack<Node*> stk;
            stk.push(root);

            while (!stk.empty())
            {
                Node* node = stk.top();
                stk.pop();

                onVisitNodeFunc(node);    // 访问节点

                // 逆序
                for (int i = node->GetChildCount() - 1; i >= 0; --i)
                {
                    // 未访问过的节点入栈
                    if (visited.find(node->GetChild(i)) == visited.end())
                    {
                        stk.push(node->GetChild(i));
                        visited.insert(node->GetChild(i));
                    }
                }
            }
        }
    protected:
        std::string m_Name;             // 节点名称
        bool m_Enable = true;           // 启用状态
        Node* m_Parent = nullptr;       // 父节点
        std::vector<Node*> m_Children;  // 子节点列表

        uint32_t m_Level = 0;           // 节点层级 从0开始
    };
}