#pragma once
#include "Core.h"

namespace Min
{

	class MIN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

