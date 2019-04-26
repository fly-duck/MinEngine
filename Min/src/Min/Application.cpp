#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Min/Log.h"


namespace Min
{

Application::Application()
{
}


Application::~Application()
{
}

void Application::Run()
{

	WindowResizeEvent e(1280, 720);
	MIN_TRACE(e);
	while (true)
	{

	}
}
}
