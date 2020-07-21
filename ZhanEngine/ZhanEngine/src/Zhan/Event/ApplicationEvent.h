#pragma once
#include "Event.h"

namespace Zhan {
	class ZHAN_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZHAN_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZHAN_API AppRenderEvent : public Event {
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}