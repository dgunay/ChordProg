/*
Progger

by Devin Gunay

Features to implement:
- Represent chord progressions absolutely and relatively
- Transpose a given chord progression
- Generate a chord progression semirandomly
- Create negative harmony version of given chord prog
- Note frequency calculation (after a tuning is selected)

Other TODO:
- Exception safety stuff (mark functions for if they throw exceptions I guess)
- Pass over all code to check for usage of const and & with params.

*/

#include "Note.h"
#include "Chord.h"
int main()
{
	for (int i = MAJOR; i < OTHER; i++)
	{
		Chord C("C", 4, i);
		std::cout << C.toString() << '\n';
	}
		
	//chords appear correct - check for correct absolutekeypos

	//find a way to choose correct enharmonicity
	//e.g. Cmin is currently showinng as C D# G.

	

	system("pause");

	return 0;
}