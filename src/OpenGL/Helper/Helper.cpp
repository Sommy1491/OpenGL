#include "OpenGL\Helper\Helper.h"

#pragma region FileHandler
std::string FileHandler::ReadFile(const char * file)
{
	std::ostringstream ss;
	std::ifstream in;
	in.open(file);

	if (!in.is_open())
		throw std::runtime_error("Unable to Open file");

	ss << in.rdbuf();
	return ss.str();
}
#pragma endregion

