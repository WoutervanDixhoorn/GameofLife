#include "TestLayer.h"

#include <iostream>

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
	std::cout << "OnLayerUpdate" << std::endl;
}

void TestLayer::OnEvent(Douter::IEvent& event)
{
	Douter::EventDispatcher dispatcher(event);

	dispatcher.Dispatch<Douter::WindowResizeEvent>(std::bind(&TestLayer::OnWindowResize, this, std::placeholders::_1));
}

void TestLayer::OnWindowResize(Douter::WindowResizeEvent& e)
{
	std::cout << "Width: " << e.GetWidth() << std::endl << "Height: " << e.GetHeight();
}