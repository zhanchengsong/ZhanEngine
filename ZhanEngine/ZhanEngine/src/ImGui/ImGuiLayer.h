#pragma once
#include "Zhan/Layer/Layer.h"
#include "Zhan/Event/Event.h"
#include "Zhan/Event/MouseEvent.h"
#include "Zhan/Event/KeyEvent.h"
#include "Zhan/Event/WindowEvent.h"

namespace Zhan {
	class ZHAN_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrollEvent(MouseScrollEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);
	protected:
		float m_Time = 0.0f;
	};
}