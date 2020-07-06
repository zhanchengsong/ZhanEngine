#pragma once
#ifdef ZH_PLATFORM_WINDOWS
// This method is implemented in the client app side
extern Zhan::Application* Zhan::CreateApplication();

int main(int argc, char** argv) {
	// Init logger
	Zhan::Log::Init();
	ZH_CORE_INFO("Starting Zhan Engine");
	auto app = Zhan::CreateApplication();
	app->Run();
	delete app;
}
#endif

