#pragma once

#ifdef WED_PLATFORM_WINDOWS

extern WEngined::Application* WEngined::CreateApplication();

int main(int argc, char** argv) {
	printf("WEngined Started!");
	auto app = WEngined::CreateApplication();
	app->Run();

	delete app;
}
#endif