#pragma once
#include "Event.h"
#include <sstream>
namespace Zhan {
	class ZHAN_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int m_Width, unsigned int m_Height) {
		}
	private:
		unsigned int m_Width, m_Height;
	};
}
