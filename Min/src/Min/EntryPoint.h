#pragma once

#ifdef MIN_PLATFORM_WINDOWS


// why we have to define this extern?
extern Min::Application* Min::CreateApplication();

int main(int argc, char** argv)
{
	Min::Log::Init();
	//Min::Log::GetCoreLogger()->trace("hello");
	MIN_CORE_WARN("Initialized Log!");
	//wchar_t a = 5;
	spdlog::error("Some error message with arg: {}");
	//std::string b = "dsjfkla;dsjao;";
	//MIN_INFO(b);
	//MIN_INFO("Hello! Var={0}",a);
	auto app = Min::CreateApplication();
	app->Run();
	delete app;
}


#endif 