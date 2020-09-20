#pragma once
#include "Zhan/Core.h"
#include "Zhan/Event/Event.h"
namespace Zhan {
	class ZHAN_API Layer
	{
	protected:
		std::string m_Debug_Name;
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImGuiRender() {}
		inline const std::string GetName() {
			return m_Debug_Name;
		}
	};
};



