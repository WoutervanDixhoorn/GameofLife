#pragma once
#include "Douter.h"

class TestLayer : public Douter::ILayer
{
public:
	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate() override;
};

