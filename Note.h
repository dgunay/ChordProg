#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <iostream>
#include "InvalidNoteException.h"

enum accidental_values{DOUBLE_FLAT = -2, FLAT = -1, 
	NATURAL = 0, 
	SHARP = 1, DOUBLE_SHARP = 2};

/*
Represents a musical note.

TODO:::
Do I need to overload <= and >= 
if I've already implemented <, >, and ==?
*/
class Note
{
public:
	Note();
	Note(const Note& copy);
	Note(const std::string& noteName, int octave);

	/*
	Returns string representation of note name and
	accidental
	*/
	std::string toString() const;

	/*
	Returns string representation of note in format:
	NoteAccidentalOctave
	*/
	std::string fullString() const;

	//returns octave of Note
	int octave() const;

	/*
	Returns 12-tone position of passed Note.
	A = 0, Bb = 1, etc
	*/
	int twelveToneIndex() const;

	bool operator <(const Note& rh) const;
	bool operator >(const Note& rh) const;
	bool operator ==(const Note& rh) const;

	//Moves note up one half-step
	Note& operator++();
	Note& operator++(int);

	//Moves note down one half-step
	Note& operator--();
	Note& operator--(int);

	Note& operator+=(int halfSteps);
	Note& operator-=(int halfSteps);

	Note operator+(int halfSteps);
	Note operator-(int halfSteps);

	Note& operator =(const Note& rh);
	friend std::ostream& operator<<
		(std::ostream& out, const Note& note);


private:
	char letterName;
	int accidental;
	int absoluteKeyboardPosition;
	
	const int MAX_KEYBOARD_INDEX = 87;

	void copy(const Note& copy);	

	/*
	Returns true if passed string is a correctly
	formatted note name.
	*/
	bool isValidNoteName(const std::string& note);
};
#endif // !NOTE_H
