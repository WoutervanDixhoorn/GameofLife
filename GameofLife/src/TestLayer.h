#pragma once

#include "Douter.h"

class TestLayer : public Douter::ILayer
{
public:
	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate() override;
	bool OnEvent(Douter::IEvent& e) override;

private:
	bool OnWindowResize(Douter::WindowResizeEvent& e);
};

