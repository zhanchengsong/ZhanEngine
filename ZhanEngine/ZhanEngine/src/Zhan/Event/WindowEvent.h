#pragma once
#include "Event.h"
namespace Zhan {
	class ZHAN_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : 
			m_Width(width), m_Height(height)
		{}
		unsigned int getWidth() { return m_Width;  }
		unsigned int getHeight() { return m_Height;  }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << " , " << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	private:
		unsigned int m_Width, m_Height;
	};

	class ZHAN_API WindowCloseEvent : public Event {
	public:
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};
}
