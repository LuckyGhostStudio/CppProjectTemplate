#include <LFrame.h>

#include <iostream>

using namespace LFrame;

int main()
{
    // 创建节点树
    GameObject* canvas = new GameObject("Canvas");

    GameObject* panel = new GameObject("MainPanel");
    canvas->AddChild(panel);

    GameObject* panel2 = new GameObject("MainPanel2");
    canvas->AddChild(panel2);

    GameObject* title = new GameObject("TitleText");
    panel->AddChild(title);

    GameObject* buttonContainer = new GameObject("ButtonContainer");
    panel->AddChild(buttonContainer);

    GameObject* playButton = new GameObject("PlayButton");
    buttonContainer->AddChild(playButton);

    GameObject* quitButton = new GameObject("QuitButton");
    buttonContainer->AddChild(quitButton);
    quitButton->SetActive(false); // 设置为非激活状态

    // 打印树形结构
    std::cout << GameObjectUtility::GameObjectToString(canvas);

    delete canvas;
    return 0;
}