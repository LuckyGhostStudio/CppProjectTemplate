#include "GameObjectUtility.h"

#include <sstream>

namespace LFrame
{
    std::string GameObjectUtility::GameObjectToString(GameObject* gameObject, bool showDetails)
    {
        std::stringstream ss;

        if (!gameObject)
        {
            return "";
        }

        gameObject->DFS([&](GameObject* gameObject)
        {
            uint32_t level = gameObject->GetLevel();

            // 根据层级缩进
            for (uint32_t i = 0; i < level; i++)
            {
                ss << "  ";
            }

            ss << gameObject->GetName() << "\n";

            if (showDetails)
            {
                // TODO 组件信息
            }
        });

        return ss.str();
    }
}
