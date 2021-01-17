#include "Douter.h"
#include "Douter/EntryPoint.h"

#include <memory>
#include <iostream>

#include "TestLayer.h"

class GameofLife : public Douter::Application
{
public:
    
    GameofLife() : Application("GameofLife")
    {
        m_TestLayer = new TestLayer();

        PushLayer(m_TestLayer);
    }

    ~GameofLife()
    {
    }

private:
    TestLayer* m_TestLayer;
};

Douter::Application* Douter::CreateApplication()
{
    return new GameofLife();
}