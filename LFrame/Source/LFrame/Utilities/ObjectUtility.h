#pragma once

#include <string>

#include "LFrame/Core/Object.h"

namespace LFrame
{
    class ObjectUtility
    {
    public:
        /// <summary>
        /// 对象转为字符串
        /// </summary>
        /// <param name="object">节点</param>
        /// <param name="showDetails">是否显示详细信息</param>
        /// <returns></returns>
        static std::string ObjectToString(Object* object, bool showDetails = false);
    };
}