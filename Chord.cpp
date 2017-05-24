#include "Chord.h"

#include <cassert>

Chord::Chord()
{
	assert(false && "TODO: Default Chord::Chord() to C Major Triad");
}

Chord::Chord(const Chord & rh)
{
	*this = rh;
}

Chord::Chord(std::string root, int octave, int harmony)
{
	this->root = root;
	Note rootNote(root, octave);

	notes.push_back(rootNote);

	switch (harmony)
	{
	case MAJOR: 
		notes.push_back(Note(rootNote + 4));
		notes.push_back(Note(rootNote + 7)); break;

	default: assert(false && "TODO: Write a default case.");
	}
}

Chord::Chord(const Note & root, int harmony)
{
}

Chord::Chord(const Note & note1, const Note &)
{
}

bool Chord::isClosedVoicing() const
{
	//ideas

	//
	return false;
}

std::string Chord::toString() const
{
	return std::string();
}

std::string Chord::slashChord() const
{
	return std::string();
}

void Chord::transpose(int halfSteps)
{
}

Chord Chord::negate()
{
	return Chord();
}

Chord & Chord::operator=(const Chord & rh)
{
	if (this != &rh)
	{
		root = rh.root;
		inversion = rh.inversion;
		harmony = rh.harmony;
		notes = rh.notes;
	}

	return *this;
}

bool Chord::operator==(const Chord & rh)
{
	return false;
}
