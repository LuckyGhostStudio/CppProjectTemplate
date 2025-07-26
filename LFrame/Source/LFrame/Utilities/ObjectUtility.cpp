#include "ObjectUtility.h"

#include <sstream>

namespace LFrame
{
    std::string ObjectUtility::ObjectToString(Object* object, bool showDetails)
    {
        std::stringstream ss;

        if (!object)
        {
            return "";
        }

        object->DFS([&](Object* object)
        {
            uint32_t level = object->GetLevel();

            // 根据层级缩进
            for (uint32_t i = 0; i < level; i++)
            {
                ss << "  ";
            }

            ss << object->m_Name << "\n";

            if (showDetails)
            {
                // TODO 组件信息
            }
        });

        return ss.str();
    }
}
