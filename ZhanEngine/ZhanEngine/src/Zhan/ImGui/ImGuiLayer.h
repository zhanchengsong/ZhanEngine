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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		void Begin();
		void End();
		void OnImGuiRender();
	protected: 
		float m_Time = 0.0f;
	};
}