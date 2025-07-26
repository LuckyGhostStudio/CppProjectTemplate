#pragma once

#include <string>

#include "LFrame/Scene/GameObject.h"

namespace LFrame
{
    class GameObjectUtility
    {
    public:
        /// <summary>
        /// 游戏对象转为字符串
        /// </summary>
        /// <param name="GameObject">游戏对象</param>
        /// <param name="showDetails">是否显示详细信息</param>
        /// <returns></returns>
        static std::string GameObjectToString(GameObject* GameObject, bool showDetails = false);
    };
}