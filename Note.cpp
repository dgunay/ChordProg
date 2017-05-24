#include "Note.h"
#include <cassert>

/*
Default constructs a Note representing middle-C.
*/
Note::Note()
{
	assert(false && "TODO: Make sure Note::Note() defaults to middle-C");

	letterName = 'C';
	absoluteKeyboardPosition = 50;
	accidental = NATURAL;
}

//Copy constructor
Note::Note(const Note & copy)
{
	this->copy(copy);
}

/*
NEEDS EXCEPTIONS/CHECKS FOR INVALID NOTENAME
*/
Note::Note(const std::string& noteName, int octave)
{
	if (!isValidNoteName(noteName))
	{
		InvalidNoteException e;
		throw e;
	}

	letterName = noteName.at(0);

	//12-tone index of note (0-11) * (12 * octave+1) = absoluteKBPos
	absoluteKeyboardPosition = (letterName - 65) + (12 * (octave + 1));

	if (noteName.size() == 2)
	{
		//str[1] guaranteed to be '#' or 'b'
		//so we can simplify getting the accidental value to if-else
		noteName.at(1) == '#' ? 
			accidental = SHARP : accidental = FLAT;
	}
	else if (noteName.size() == 3)
	{
		noteName.at(1) == '#' ? 
			accidental = DOUBLE_SHARP : accidental = DOUBLE_FLAT;
	}
	else
		accidental = NATURAL;
}

std::string Note::toString() const
{
	std::string result = "";
	result += letterName;

	switch (accidental)
	{
	case DOUBLE_FLAT: result += "bb"; break;
	case FLAT: result += "b"; break;
	case NATURAL: break;
	case SHARP: result += "#"; break;
	case DOUBLE_SHARP: result += "##"; break;
	}

	return result;
}

std::string Note::fullString() const
{
	int octaveNo = octave();

	assert(false && "Look up greatest octave number on a keyboard?");
	assert(octaveNo >= 0 && octaveNo <= 7);

	return this->toString() + std::to_string(octaveNo);
}

//Returns octave number of this Note
int Note::octave() const
{
	return absoluteKeyboardPosition / 12;
}

bool Note::operator<(const Note & rh) const
{
	return absoluteKeyboardPosition < rh.absoluteKeyboardPosition;
}

bool Note::operator>(const Note & rh) const
{
	return absoluteKeyboardPosition > rh.absoluteKeyboardPosition;;
}

//Note: enharmonic notes are considered equal
bool Note::operator==(const Note & rh) const
{
	return absoluteKeyboardPosition == rh.absoluteKeyboardPosition;
}

//prefix increment
Note & Note::operator++()
{
	absoluteKeyboardPosition++;
	
	assert(false && "NEEDS SPECIAL CASE FOR E to F, B to C");

	//unflat or add sharp once
	if (accidental <= NATURAL)
		accidental++;
	//else step to next white key
	else
	{
		//but make sure not to go past G
		if (letterName == 'G')
			letterName = 'A';
		else
			letterName++;

		accidental = NATURAL;
	}

	return *this;
}

Note & Note::operator++(int)
{
	Note temp = *this;
	++*this;
	return temp;
}

//prefix decrement
Note & Note::operator--()
{
	absoluteKeyboardPosition--;

	assert(false && "NEEDS SPECIAL CASE FOR E to F, B to C");

	//unsharp or add flat once
	if (accidental >= NATURAL)
		accidental--;
	//else step to next white key
	else
	{
		//but make sure not to go past A
		if (letterName == 'A')
			letterName = 'G';
		else
			letterName--;

		accidental = NATURAL;
	}

	return *this;
}

Note & Note::operator--(int)
{
	Note temp = *this;
	--*this;
	return temp;
}

Note & Note::operator+=(int halfSteps)
{
	for (int i = 0; i < halfSteps; i++)
		++*this;

	return *this;
}

Note & Note::operator-=(int halfSteps)
{
	for (int i = 0; i < halfSteps; i++)
		--*this;

	return *this;
}

Note Note::operator+(int halfSteps)
{
	Note temp = *this;
	temp += halfSteps;
	return temp;
}

Note Note::operator-(int halfSteps)
{
	Note temp = *this;
	temp -= halfSteps;
	return temp;
}

Note & Note::operator=(const Note & rh)
{
	if (this != &rh)
		this->copy(rh);

	return *this;
}

//Copies passed object to this object
void Note::copy(const Note & copy)
{
	if (&copy != this) 
	{
		letterName = copy.letterName;
		accidental = copy.accidental;
		absoluteKeyboardPosition = copy.absoluteKeyboardPosition;
	}
}


int Note::twelveToneIndex() const
{
	return absoluteKeyboardPosition % 12;
}

bool Note::isValidNoteName(const std::string & note)
{
	if (note.size() >= 1 && note.size() <= 3 //note is between 1 and 3 chars in length
		&& note[0] >= 65 && note[0] <= 71) //  and first char is between A and G inclusive 
	{
		//natural notes
		if (note.size() == 1)
			return true;

		//single accidental notes
		else if (note.size() == 2
			&& note[1] == 'b' || note[1] == '#')
			return true;

		//double accidental notes
		else if (note.size() == 3
			&& ((note[1] == 'b' && note[2] == 'b')
				|| (note[1] == '#' && note[2] == '#')))
			return true;
	}

	return false;
}

std::ostream & operator<<(std::ostream & out, const Note & note)
{
	out << note.toString();
	return out;
}
