/*
	Jeffrey Carson
	CS302
	10/26/20
	Not Found Exception File
*/

#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string& message) : std::logic_error("Not Found Exception: " + message)
{
}