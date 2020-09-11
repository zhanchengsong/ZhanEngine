#pragma once
#include <ostream>
namespace Zhan
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define ZH_KEY_SPACE           ::Zhan::Key::Space
#define ZH_KEY_APOSTROPHE      ::Zhan::Key::Apostrophe    /* ' */
#define ZH_KEY_COMMA           ::Zhan::Key::Comma         /* , */
#define ZH_KEY_MINUS           ::Zhan::Key::Minus         /* - */
#define ZH_KEY_PERIOD          ::Zhan::Key::Period        /* . */
#define ZH_KEY_SLASH           ::Zhan::Key::Slash         /* / */
#define ZH_KEY_0               ::Zhan::Key::D0
#define ZH_KEY_1               ::Zhan::Key::D1
#define ZH_KEY_2               ::Zhan::Key::D2
#define ZH_KEY_3               ::Zhan::Key::D3
#define ZH_KEY_4               ::Zhan::Key::D4
#define ZH_KEY_5               ::Zhan::Key::D5
#define ZH_KEY_6               ::Zhan::Key::D6
#define ZH_KEY_7               ::Zhan::Key::D7
#define ZH_KEY_8               ::Zhan::Key::D8
#define ZH_KEY_9               ::Zhan::Key::D9
#define ZH_KEY_SEMICOLON       ::Zhan::Key::Semicolon     /* ; */
#define ZH_KEY_EQUAL           ::Zhan::Key::Equal         /* = */
#define ZH_KEY_A               ::Zhan::Key::A
#define ZH_KEY_B               ::Zhan::Key::B
#define ZH_KEY_C               ::Zhan::Key::C
#define ZH_KEY_D               ::Zhan::Key::D
#define ZH_KEY_E               ::Zhan::Key::E
#define ZH_KEY_F               ::Zhan::Key::F
#define ZH_KEY_G               ::Zhan::Key::G
#define ZH_KEY_H               ::Zhan::Key::H
#define ZH_KEY_I               ::Zhan::Key::I
#define ZH_KEY_J               ::Zhan::Key::J
#define ZH_KEY_K               ::Zhan::Key::K
#define ZH_KEY_L               ::Zhan::Key::L
#define ZH_KEY_M               ::Zhan::Key::M
#define ZH_KEY_N               ::Zhan::Key::N
#define ZH_KEY_O               ::Zhan::Key::O
#define ZH_KEY_P               ::Zhan::Key::P
#define ZH_KEY_Q               ::Zhan::Key::Q
#define ZH_KEY_R               ::Zhan::Key::R
#define ZH_KEY_S               ::Zhan::Key::S
#define ZH_KEY_T               ::Zhan::Key::T
#define ZH_KEY_U               ::Zhan::Key::U
#define ZH_KEY_V               ::Zhan::Key::V
#define ZH_KEY_W               ::Zhan::Key::W
#define ZH_KEY_X               ::Zhan::Key::X
#define ZH_KEY_Y               ::Zhan::Key::Y
#define ZH_KEY_Z               ::Zhan::Key::Z
#define ZH_KEY_LEFT_BRACKET    ::Zhan::Key::LeftBracket   /* [ */
#define ZH_KEY_BACKSLASH       ::Zhan::Key::Backslash     /* \ */
#define ZH_KEY_RIGHT_BRACKET   ::Zhan::Key::RightBracket  /* ] */
#define ZH_KEY_GRAVE_ACCENT    ::Zhan::Key::GraveAccent   /* ` */
#define ZH_KEY_WORLD_1         ::Zhan::Key::World1        /* non-US #1 */
#define ZH_KEY_WORLD_2         ::Zhan::Key::World2        /* non-US #2 */

/* Function keys */
#define ZH_KEY_ESCAPE          ::Zhan::Key::Escape
#define ZH_KEY_ENTER           ::Zhan::Key::Enter
#define ZH_KEY_TAB             ::Zhan::Key::Tab
#define ZH_KEY_BACKSPACE       ::Zhan::Key::Backspace
#define ZH_KEY_INSERT          ::Zhan::Key::Insert
#define ZH_KEY_DELETE          ::Zhan::Key::Delete
#define ZH_KEY_RIGHT           ::Zhan::Key::Right
#define ZH_KEY_LEFT            ::Zhan::Key::Left
#define ZH_KEY_DOWN            ::Zhan::Key::Down
#define ZH_KEY_UP              ::Zhan::Key::Up
#define ZH_KEY_PAGE_UP         ::Zhan::Key::PageUp
#define ZH_KEY_PAGE_DOWN       ::Zhan::Key::PageDown
#define ZH_KEY_HOME            ::Zhan::Key::Home
#define ZH_KEY_END             ::Zhan::Key::End
#define ZH_KEY_CAPS_LOCK       ::Zhan::Key::CapsLock
#define ZH_KEY_SCROLL_LOCK     ::Zhan::Key::ScrollLock
#define ZH_KEY_NUM_LOCK        ::Zhan::Key::NumLock
#define ZH_KEY_PRINT_SCREEN    ::Zhan::Key::PrintScreen
#define ZH_KEY_PAUSE           ::Zhan::Key::Pause
#define ZH_KEY_F1              ::Zhan::Key::F1
#define ZH_KEY_F2              ::Zhan::Key::F2
#define ZH_KEY_F3              ::Zhan::Key::F3
#define ZH_KEY_F4              ::Zhan::Key::F4
#define ZH_KEY_F5              ::Zhan::Key::F5
#define ZH_KEY_F6              ::Zhan::Key::F6
#define ZH_KEY_F7              ::Zhan::Key::F7
#define ZH_KEY_F8              ::Zhan::Key::F8
#define ZH_KEY_F9              ::Zhan::Key::F9
#define ZH_KEY_F10             ::Zhan::Key::F10
#define ZH_KEY_F11             ::Zhan::Key::F11
#define ZH_KEY_F12             ::Zhan::Key::F12
#define ZH_KEY_F13             ::Zhan::Key::F13
#define ZH_KEY_F14             ::Zhan::Key::F14
#define ZH_KEY_F15             ::Zhan::Key::F15
#define ZH_KEY_F16             ::Zhan::Key::F16
#define ZH_KEY_F17             ::Zhan::Key::F17
#define ZH_KEY_F18             ::Zhan::Key::F18
#define ZH_KEY_F19             ::Zhan::Key::F19
#define ZH_KEY_F20             ::Zhan::Key::F20
#define ZH_KEY_F21             ::Zhan::Key::F21
#define ZH_KEY_F22             ::Zhan::Key::F22
#define ZH_KEY_F23             ::Zhan::Key::F23
#define ZH_KEY_F24             ::Zhan::Key::F24
#define ZH_KEY_F25             ::Zhan::Key::F25

/* Keypad */
#define ZH_KEY_KP_0            ::Zhan::Key::KP0
#define ZH_KEY_KP_1            ::Zhan::Key::KP1
#define ZH_KEY_KP_2            ::Zhan::Key::KP2
#define ZH_KEY_KP_3            ::Zhan::Key::KP3
#define ZH_KEY_KP_4            ::Zhan::Key::KP4
#define ZH_KEY_KP_5            ::Zhan::Key::KP5
#define ZH_KEY_KP_6            ::Zhan::Key::KP6
#define ZH_KEY_KP_7            ::Zhan::Key::KP7
#define ZH_KEY_KP_8            ::Zhan::Key::KP8
#define ZH_KEY_KP_9            ::Zhan::Key::KP9
#define ZH_KEY_KP_DECIMAL      ::Zhan::Key::KPDecimal
#define ZH_KEY_KP_DIVIDE       ::Zhan::Key::KPDivide
#define ZH_KEY_KP_MULTIPLY     ::Zhan::Key::KPMultiply
#define ZH_KEY_KP_SUBTRACT     ::Zhan::Key::KPSubtract
#define ZH_KEY_KP_ADD          ::Zhan::Key::KPAdd
#define ZH_KEY_KP_ENTER        ::Zhan::Key::KPEnter
#define ZH_KEY_KP_EQUAL        ::Zhan::Key::KPEqual

#define ZH_KEY_LEFT_SHIFT      ::Zhan::Key::LeftShift
#define ZH_KEY_LEFT_CONTROL    ::Zhan::Key::LeftControl
#define ZH_KEY_LEFT_ALT        ::Zhan::Key::LeftAlt
#define ZH_KEY_LEFT_SUPER      ::Zhan::Key::LeftSuper
#define ZH_KEY_RIGHT_SHIFT     ::Zhan::Key::RightShift
#define ZH_KEY_RIGHT_CONTROL   ::Zhan::Key::RightControl
#define ZH_KEY_RIGHT_ALT       ::Zhan::Key::RightAlt
#define ZH_KEY_RIGHT_SUPER     ::Zhan::Key::RightSuper
#define ZH_KEY_MENU            ::Zhan::Key::Menu