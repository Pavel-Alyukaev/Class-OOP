#pragma once
#include <string> 
#include <sstream>
#include"Polynom.h"

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

