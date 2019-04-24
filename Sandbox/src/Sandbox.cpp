

#include <Min_Engine.h>


class Sandbox : public Min::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Min::Application* Min::CreateApplication()
{
	return new Sandbox();

}


