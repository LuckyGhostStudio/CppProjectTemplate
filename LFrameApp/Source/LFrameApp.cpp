#include <LFrame.h>

#include <iostream>

using namespace LFrame;
using namespace LFrame::UI;

int main()
{
    // 创建节点树
    UINode* canvas = new UINode("Canvas");

    UINode* panel = new UINode("MainPanel");
    canvas->AddChild(panel);

    UINode* panel2 = new UINode("MainPanel2");
    canvas->AddChild(panel2);

    UINode* title = new UINode("TitleText");
    panel->AddChild(title);

    UINode* buttonContainer = new UINode("ButtonContainer");
    panel->AddChild(buttonContainer);

    UINode* playButton = new UINode("PlayButton");
    buttonContainer->AddChild(playButton);

    UINode* quitButton = new UINode("QuitButton");
    buttonContainer->AddChild(quitButton);
    quitButton->SetActive(false); // 设置为非激活状态

    // 打印树形结构
    std::cout << NodeUtility::NodeToString(canvas);

    delete canvas;
    return 0;
}