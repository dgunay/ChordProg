#include "InvalidNoteException.h"

InvalidNoteException::InvalidNoteException()
{
	msg = "Invalid note.";
}

const char * InvalidNoteException::what() const
{
	return msg.c_str();
}
