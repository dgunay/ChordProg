#include "Chord.h"

#include <cassert>

Chord::Chord()
{
	assert(false && "TODO: Default Chord::Chord() to C Major Triad");
}

/*
	Copy constructor
*/
Chord::Chord(const Chord & rh)
{
	*this = rh;
}

Chord::Chord(std::string root, int octave, int harmony)
{
	this->root = root;
	Note rootNote(root, octave);
	this->harmony = harmony;

	notes.push_back(rootNote);

	switch (harmony)
	{
	case MAJOR:
		notes.push_back(Note(rootNote + MAJ_THIRD));
		notes.push_back(Note(rootNote + P_FIFTH));
		break;
	case MINOR:
		notes.push_back(Note(rootNote + MIN_THIRD));
		notes.push_back(Note(rootNote + P_FIFTH));
		break;
	case DIMINISHED:
		notes.push_back(Note(rootNote + MIN_THIRD));
		notes.push_back(Note(rootNote + TRITONE));
		break;
	case AUGMENTED:
		notes.push_back(Note(rootNote + MAJ_THIRD));
		notes.push_back(Note(rootNote + intervals::MIN_SIXTH));
		break;
	case chords::MAJOR_SEVENTH:
		notes.push_back(Note(rootNote + MAJ_THIRD));
		notes.push_back(Note(rootNote + P_FIFTH));
		notes.push_back(Note(rootNote + intervals::MAJ_SEVENTH));
		break;
	case DOMINANT_SEVENTH:
		notes.push_back(Note(rootNote + MAJ_THIRD));
		notes.push_back(Note(rootNote + P_FIFTH));
		notes.push_back(Note(rootNote + intervals::MIN_SEVENTH));
		break;
	case chords::MINOR_SEVENTH:
		notes.push_back(Note(rootNote + MIN_THIRD));
		notes.push_back(Note(rootNote + P_FIFTH));
		notes.push_back(Note(rootNote + intervals::MIN_SEVENTH));
		break;
	case HALF_DIM_SEVENTH:
		notes.push_back(Note(rootNote + MIN_THIRD));
		notes.push_back(Note(rootNote + TRITONE));
		notes.push_back(Note(rootNote + intervals::MIN_SEVENTH));
		break;
	case DIM_SEVENTH:
		notes.push_back(Note(rootNote + MIN_THIRD));
		notes.push_back(Note(rootNote + TRITONE));
		notes.push_back(Note(rootNote + intervals::MAJ_SIXTH));
		break;
	case POWER:
		notes.push_back(Note(rootNote + P_FIFTH));
		notes.push_back(Note(rootNote + OCTAVE));
		break;
	default: assert(false && "TODO: Write a default case.");
	}
}

Chord::Chord(const Note & root, int harmony)
{
	*this = Chord(root.toString(), root.octave(), harmony);
}

Chord::Chord(const Note & note1, const Note &)
{
	//TODO: check definition
}

bool Chord::isClosedVoicing() const
{
	//ideas

	/*
	No closed voicing chord has an interval exceeding
	P4. Cycle through the chord and check for this.
	*/

	
	return false;
}

std::string Chord::toString() const
{
	std::string chordStr;

	auto it = notes.begin();

	while (it != notes.end())
	{
		chordStr += it->toString();

		it++;

		if (it != notes.end())
			chordStr += ", ";
	}

	return chordStr;
}

std::string Chord::slashChord() const
{
	//find tonality of the chord

	//find lowest Note by absolute position

	//return lowest Note.letterName / tonality

	assert(false && "slashChord() unfinished.");
	return std::string();
}

void Chord::transpose(int halfSteps)
{
	//just move all the notes
	auto it = notes.begin();

	while (it != notes.end())
	{
		*it += halfSteps;
		it++;
	}
}

Chord Chord::negate()
{
	//read up on negative harmony, and implement it here.

	assert(false && "negate() unfinished.");
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

/*
	Returns true if this is the exact same chord 
	as rh.
*/
bool Chord::operator==(const Chord & rh)
{
	return this == &rh
		|| (root == rh.root
			&& inversion == rh.inversion
			&& harmony == rh.harmony
			&& notes == rh.notes);
}
