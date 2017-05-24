#ifndef CHORD_H
#define CHORD_H

enum chords {MAJOR, MINOR, DIMINISHED, AUGMENTED, 
		MAJOR_SEVENTH, DOMINANT_SEVENTH, MINOR_SEVENTH,
		HALF_DIM_SEVENTH, DIM_SEVENTH, POWER, OTHER};

enum inversions{ROOT_POSITION, FIRST_INVERSION, SECOND_INVERSION, THIRD_INVERSION};

#include <vector>
#include <memory>
#include "Note.h"


/*
Represents a chord by aggregating Note
objects.

NOTES:
- What is the best container to use here?
- How can I elegantly avoid misspelling chords
with tricky accidentals?
- How can I incoporate shell voicings?
*/
class Chord
{
public:
	Chord();
	Chord(const Chord& rh);
	Chord(std::string root, int octave, int harmony);
	Chord(const Note& root, int harmony);

	/*
	What is the syntax for a function accepting an
	indefinite amount of parametsr?
	*/
	Chord(const Note& note1, const Note&);

	bool isClosedVoicing() const;
	std::string toString() const;
	std::string slashChord() const;
	void transpose(int halfSteps);

	/*
	Need research to implement properly
	Look up negative harmony
	*/
	Chord negate();

	Chord& operator=(const Chord& rh);
	bool operator==(const Chord& rh);

private:
	std::string root;
	int inversion;
	int harmony;
	std::vector<Note> notes;
};
#endif // !CHORD_H
