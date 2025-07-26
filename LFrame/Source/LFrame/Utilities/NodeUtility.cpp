#include "NodeUtility.h"

#include <sstream>

namespace LFrame
{
    std::string NodeUtility::NodeToString(Node* node, bool showDetails)
    {
        std::stringstream ss;

        if (!node)
        {
            return "";
        }

        node->DFS([&](Node* node)
        {
            uint32_t level = node->GetLevel();

            // 根据层级缩进
            for (uint32_t i = 0; i < level; i++)
            {
                ss << "  ";
            }

            ss << node->m_Name << "\n";

            if (showDetails)
            {
                // TODO 组件信息
            }
        });

        return ss.str();
    }
}
