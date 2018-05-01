#pragma once

#include <iostream>

#pragma region FileHandler

#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace FileHandler
{
	std::string ReadFile(const char* file);
}
#pragma endregion