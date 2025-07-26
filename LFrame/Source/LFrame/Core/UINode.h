#pragma once

#include "Node.h"

namespace LFrame::UI
{
    /// <summary>
    /// UI节点基类
    /// </summary>
    class UINode : public Node
    {
    public:
        explicit UINode(const std::string& name);
    };
}