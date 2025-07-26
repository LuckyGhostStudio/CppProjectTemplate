#pragma once

#include <memory>

namespace LFrame
{
    /// <summary>
    /// 唯一指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    template<typename T>
    using Scope = std::unique_ptr<T>;

    /// <summary>
    /// 创建唯一指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    /// <typeparam name="...Args">参数类型列表</typeparam>
    /// <param name="...args">参数列表</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// 共享指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    template<typename T>
    using Ref = std::shared_ptr<T>;

    /// <summary>
    /// 创建共享指针
    /// </summary>
    /// <typeparam name="T">类型</typeparam>
    /// <typeparam name="...Args">参数类型列表</typeparam>
    /// <param name="...args">参数列表</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}