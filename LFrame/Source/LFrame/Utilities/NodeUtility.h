#pragma once

#include <string>

#include "LFrame/Core/Node.h"

namespace LFrame
{
    class NodeUtility
    {
    public:
        /// <summary>
        /// 节点转为字符串
        /// </summary>
        /// <param name="node">节点</param>
        /// <param name="showDetails">是否显示详细信息</param>
        /// <returns></returns>
        static std::string NodeToString(Node* node, bool showDetails = false);
    };
}