#include "Core.h"

#include <graphics.h>

namespace Core {

    void Demo()
    {
        // 创建绘图窗口
        initgraph(1080, 720);

        int x = 300;
        int y = 300;

        // 创建后缓冲区：之后的渲染操作都在后缓冲区进行
        BeginBatchDraw();

        while (true)
        {
            // 处理输入
            ExMessage msg;
            while (peekmessage(&msg))
            {
                if (msg.message == WM_MOUSEMOVE)
                {
                    x = msg.x;
                    y = msg.y;
                }
            }

            // 清除当前缓冲区
            cleardevice();

            // 渲染
            solidcircle(x, y, 100);

            // 交换前后缓冲区
            FlushBatchDraw();
        }

        // 关闭后缓冲区渲染模式
        EndBatchDraw();

        // 关闭绘图窗口
        closegraph();
    }
}