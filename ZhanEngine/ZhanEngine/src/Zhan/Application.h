#pragma once
#include "Core.h"
namespace Zhan {
	class ZHAN_API Application
	{
	public:
		Application(); 
		virtual ~Application();
		void Run();
	};
	// This method is going to be defined in the client app 
	Application* CreateApplication();
}

