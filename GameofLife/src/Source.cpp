#include "Douter.h"
#include "Douter/EntryPoint.h"

#include <iostream>

class GameofLife : public Douter::Application
{
public:
    
    GameofLife() : Application("GameofLife")
    {
    }

    ~GameofLife()
    {
    }

};

Douter::Application* Douter::CreateApplication()
{
    return new GameofLife();
}