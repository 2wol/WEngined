#pragma once

#ifdef WED_PLATFORM_WINDOWS

extern WEngined::Application* WEngined::CreateApplication();

int main(int argc, char** argv) {
	WEngined::Log::Init();
	HZ_CORE_WARN("Initialized Logger.");

	auto app = WEngined::CreateApplication();
	app->Run();

	delete app;
}
#endif