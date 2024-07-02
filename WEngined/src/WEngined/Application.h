#pragma once

#include "Core.h"

namespace WEngined {

	class WENGINED_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}