#pragma once
#include "Event.h"
namespace Zhan {
	// KeyEvent inherites from general Event 
	class ZHAN_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode;  }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) 
			: m_KeyCode(keycode)
		{}
		int m_KeyCode;
	};
	// KeyPressed Event 
	class ZHAN_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount):
			KeyEvent(keyCode), m_RepeatCount(repeatCount) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};
	// KeyRelease Event 
	class ZHAN_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode):
			KeyEvent(keyCode) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)

	};

}

