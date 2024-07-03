#pragma once

#include "WEngined/Log.h"
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <spdlog/fmt/ostr.h>
#include <spdlog/fmt/bundled/ostream.h>
#include <spdlog/fmt/bundled/format.h>

#ifdef WED_PLATFORM_WINDOWS
	#include <Windows.h>
#endif