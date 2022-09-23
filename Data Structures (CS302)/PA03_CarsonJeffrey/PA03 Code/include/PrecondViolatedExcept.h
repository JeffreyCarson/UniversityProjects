/*
	Jeffrey Carson
	CS302
	10/26/20
	Precond Exception File
*/

#ifndef PRECONDVIOLATEDEXCEPT_H
#define PRECONDVIOLATEDEXCEPT_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
	public:
		PrecondViolatedExcept(const std::string & message = "");
};
#endif