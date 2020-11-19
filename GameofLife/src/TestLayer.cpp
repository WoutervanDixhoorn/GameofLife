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
