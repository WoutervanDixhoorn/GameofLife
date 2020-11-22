#include "TestLayer.h"

#include <iostream>

#include "Douter.h"

void TestLayer::OnAttach()
{
	std::cout << "Attaching TestLayer!" << std::endl;
}

void TestLayer::OnDetach()
{
	std::cout << "Detaching TestLayer!" << std::endl;
}

void TestLayer::OnUpdate()
{

}

bool TestLayer::OnEvent(Douter::IEvent& e)
{
	Douter::EventDispatcher dispatcher(e);

	dispatcher.Dispatch<Douter::WindowResizeEvent>(std::bind(&TestLayer::OnWindowResize, this, std::placeholders::_1));

	return true;
}

bool TestLayer::OnWindowResize(Douter::WindowResizeEvent& e)
{
	std::cout << "Width: " << e.GetWidth() << std::endl << "Height: " << e.GetWidth() << std::endl;
	return true;
}