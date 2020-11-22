#include "Douter.h"
#include "Douter/EntryPoint.h"

#include <iostream>

#include "TestLayer.h"

class GameofLife : public Douter::Application
{
public:
    
    GameofLife() : Application("GameofLife")
    {
        m_TestLayer = new TestLayer();
        m_ImGuiLayer = new Douter::ImGuiLayer();

        PushLayer(m_TestLayer);
        PushLayer(m_ImGuiLayer);
    }

    ~GameofLife()
    {
    }

private:
    TestLayer* m_TestLayer;
    Douter::ImGuiLayer* m_ImGuiLayer;
};

Douter::Application* Douter::CreateApplication()
{
    return new GameofLife();
}