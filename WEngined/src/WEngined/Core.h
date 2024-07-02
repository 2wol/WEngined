#pragma once

#ifdef WED_PLATFORM_WINDOWS
	#ifdef WED_BUILD_DLL
		#define WENGINED_API _declspec(dllexport)
	#else
		#define WENGINED_API _declspec(dllimport)
	#endif
#else
	#error WEngined only supports Windows Platform!
#endif