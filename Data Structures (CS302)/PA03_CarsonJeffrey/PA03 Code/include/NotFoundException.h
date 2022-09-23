/*
	Jeffrey Carson
	CS302
	10/26/20
	Not Found Exception File
*/

#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

class NotFoundException: public std::logic_error 
{
	public:
		NotFoundException(const std::string& message = ""); 
}; 
#endif