#pragma once
#ifdef ZH_PLATFORM_WINDOWS
// This method is implemented in the client app side
extern Zhan::Application* Zhan::CreateApplication();

int main(int argc, char** argv) {

	Zhan::Log::Init();

	auto app = Zhan::CreateApplication();
	app->Run();
	delete app;
}
#endif

