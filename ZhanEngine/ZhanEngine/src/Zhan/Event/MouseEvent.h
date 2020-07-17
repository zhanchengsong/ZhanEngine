#pragma once
#include "Event.h"

namespace Zhan {
	class ZHAN_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) :
			m_Mouse_X(x), m_Mouse_Y(y) {}
		inline float getX() { return m_Mouse_X; }
		inline float getY() { return m_Mouse_Y; }
		
		std::string ToString() const override {
			std::stringstream ss; 
			ss << "MouseMovedEvent: " << m_Mouse_X << "," << m_Mouse_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput) // both bits are set here 
	private:
		float m_Mouse_X, m_Mouse_Y;
	};

	class ZHAN_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float xoffset, float yoffset):
			m_XOffset(xoffset), m_YOffset(yoffset)
		{}
		inline float getXOffSet() { return m_XOffset; }
		inline float getYOffSet() { return m_YOffset; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << " , " << m_YOffset; 
			return ss.str();
		} 
		EVENT_CLASS_TYPE(MoseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};
	// Base case for Mouse Button Events, should be extended to pressed and released
	class ZHAN_API MouseButtonEvent : public Event {
	public:
		inline int getMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button):
			m_Button(button)
		{}
		int m_Button;
		
	};

	class ZHAN_API MouseButtonPressedEvent : public MouseButtonEvent {
	public: 
		MouseButtonPressedEvent(int button):
			MouseButtonEvent(button) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MousePressedEvent " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ZHAN_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseReleasedEvent " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
