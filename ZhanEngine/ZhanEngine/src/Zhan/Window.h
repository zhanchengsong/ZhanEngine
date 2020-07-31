#pragma once
#include "zhpch.h"
#include "Zhan/Core.h"
#include "Zhan/Event/Event.h"

namespace Zhan {
	struct WindowProps {
		std::string Title;
		unsigned int Height;
		unsigned int Width;
		WindowProps(const std::string& title="Zhan Engine", unsigned int width = 1280 , unsigned int height = 720):
			Title(title), Width(width), Height(height) {}
	}; 

	class ZHAN_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void* GetNativeWindow() const = 0;
		static Window* Create(const WindowProps& props = WindowProps());

	};
}