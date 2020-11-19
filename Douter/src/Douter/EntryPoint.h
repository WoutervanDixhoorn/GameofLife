#pragma once

extern Douter::Application* Douter::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Douter::CreateApplication();
	app->run();
	delete app;
	return 0;
}