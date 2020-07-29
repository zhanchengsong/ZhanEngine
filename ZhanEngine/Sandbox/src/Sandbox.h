#pragma once
#include <Zhan.h>
class Sandbox : public Zhan::Application
{
public:
	Sandbox() {
		PushLayer(new Zhan::ImGuiLayer());
	}
	~Sandbox() {}
};
