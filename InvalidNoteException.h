#ifndef INVALIDNOTEEXCEPTION_H
#define INVALIDNOTEEXCEPTION_H

#include <exception>
#include <string>

class InvalidNoteException : public std::exception
{
public:
	InvalidNoteException();

	const char* what() const;
private:
	std::string msg;
};
#endif // !INVALIDNOTEEXCEPTION_H
