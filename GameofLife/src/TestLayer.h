#pragma once
#include "Douter.h"

class TestLayer : public Douter::ILayer
{
public:
	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate() override;
	void OnEvent(Douter::IEvent& event) override;

private:
	void OnWindowResize(Douter::WindowResizeEvent& e);
};

