#pragma once
#include<ostream>
namespace Zhan
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define ZH_MOUSE_BUTTON_0      ::Zhan::Mouse::Button0
#define ZH_MOUSE_BUTTON_1      ::Zhan::Mouse::Button1
#define ZH_MOUSE_BUTTON_2      ::Zhan::Mouse::Button2
#define ZH_MOUSE_BUTTON_3      ::Zhan::Mouse::Button3
#define ZH_MOUSE_BUTTON_4      ::Zhan::Mouse::Button4
#define ZH_MOUSE_BUTTON_5      ::Zhan::Mouse::Button5
#define ZH_MOUSE_BUTTON_6      ::Zhan::Mouse::Button6
#define ZH_MOUSE_BUTTON_7      ::Zhan::Mouse::Button7
#define ZH_MOUSE_BUTTON_LAST   ::Zhan::Mouse::ButtonLast
#define ZH_MOUSE_BUTTON_LEFT   ::Zhan::Mouse::ButtonLeft
#define ZH_MOUSE_BUTTON_RIGHT  ::Zhan::Mouse::ButtonRight
#define ZH_MOUSE_BUTTON_MIDDLE ::Zhan::Mouse::ButtonMiddle