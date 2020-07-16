#pragma once
#include "Zhan/Core.h"
#include <string>
#include <functional>

namespace Zhan {
	// Use enum class whenever possible to ensure type safety and able to reuse varaible name 
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MoseScrolled
	};
	// BIT(x) means a bit 1 at x'th position, we can later do a mask at the event 
	// We use enum here instead of enum class so we can either do bit mask or pass the enum into Macro 
	// it will be treated as a normal int 
	enum EventCategory {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput		    = BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton    = BIT(4),
		EventCategoryWindow         = BIT(5)
		
	};
// This is a macro to generate repetitive body methods 
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; } \
						 virtual EventType GetEventType() const override {return GetStaticType(); } \
					     virtual const char* GetName() const override {return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }
	// Main class of the Event 
	class ZHAN_API Event {
		friend class EventDispatcher; 
	public:
		virtual EventType GetEventType() const = 0; // Pure virtual function, to be implemented in subclass 
		virtual const char* GetName() const = 0; 
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category; // Use bit mask to find out category 
		}
	protected:
		bool m_Handled = false;

	};

	class EventDispatcher {
		// Convinient function pointer type, the function returns a bool, takes in a T& as parameter
		// Template typename T only affects what is followed right after 
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) :
			m_Event(event) {}

		template<typename T> // We can make function a deducible type later 
		bool Dispatch(EventFn<T> func) { // We did not check if T extends Event class, may be a problem later 
			if (m_Event.GetEventType == T::GetStaticType()) {
				// Check if the Dispatcher<T> can dispatch Event 
				m_Event.m_Handled = func(static_cast<T&> m_Event); // We used static cast to cast Event to its derived class reference because base has virtual functions
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}

