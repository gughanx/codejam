#include "MagicTrick.h"

namespace CodeJam
{

void MagicTrick::readProblem()
{
	read(firstChosenRow.id);
	--firstChosenRow.id;
	skip(firstChosenRow.id * 4);
	read(firstChosenRow.contents, 4);
	skip((4 - firstChosenRow.id - 1) * 4);

	read(secondChosenRow.id);
	--secondChosenRow.id;
	skip(secondChosenRow.id * 4);
	read(secondChosenRow.contents, 4);
	skip((4 - secondChosenRow.id - 1) * 4);
}

void MagicTrick::solveProblem(std::stringstream& output)
{
	size_t totalNumberOfMatches = 0;
	size_t chosenNumber = 0;
	bool foundChosenNumber = false;

	for (size_t i = 0; i < 4; ++i)
	{
		size_t numberOfMatchesInRow = 0;

		for (size_t j = 0; j < 4; ++j)
		{
			if (firstChosenRow.contents[i] == secondChosenRow.contents[j])
			{
				++numberOfMatchesInRow;
			}
		}

		totalNumberOfMatches += numberOfMatchesInRow;

		if (numberOfMatchesInRow == 1)
		{
			chosenNumber = firstChosenRow.contents[i];
			foundChosenNumber = true;
		}
	}

	if (totalNumberOfMatches > 1)
	{
		output << "Bad magician!";
	}
	else if (foundChosenNumber)
	{
		output << chosenNumber;
	}
	else
	{
		output << "Volunteer cheated!";
	}
}

} // namespace CodeJam