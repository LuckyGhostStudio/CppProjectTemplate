#include "Core.h"

#include <graphics.h>

namespace Core {

    void Demo()
    {
        // ������ͼ����
        initgraph(1080, 720);

        int x = 300;
        int y = 300;

        // �����󻺳�����֮�����Ⱦ�������ں󻺳�������
        BeginBatchDraw();

        while (true)
        {
            // ��������
            ExMessage msg;
            while (peekmessage(&msg))
            {
                if (msg.message == WM_MOUSEMOVE)
                {
                    x = msg.x;
                    y = msg.y;
                }
            }

            // �����ǰ������
            cleardevice();

            // ��Ⱦ
            solidcircle(x, y, 100);

            // ����ǰ�󻺳���
            FlushBatchDraw();
        }

        // �رպ󻺳�����Ⱦģʽ
        EndBatchDraw();

        // �رջ�ͼ����
        closegraph();
    }
}