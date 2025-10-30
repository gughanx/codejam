#include "MagicTrick.h"

namespace CodeJam
{

/**
 * @brief Reads the input for a single test case.
 */
void MagicTrick::readProblem()
{
	// Read the ID of the first chosen row.
	read(firstChosenRow.id);
	// Decrement the ID to be zero-based.
	--firstChosenRow.id;
	// Skip the rows before the chosen one.
	skip(firstChosenRow.id * 4);
	// Read the contents of the chosen row.
	read(firstChosenRow.contents, 4);
	// Skip the rows after the chosen one.
	skip((4 - firstChosenRow.id - 1) * 4);

	// Read the ID of the second chosen row.
	read(secondChosenRow.id);
	// Decrement the ID to be zero-based.
	--secondChosenRow.id;
	// Skip the rows before the chosen one.
	skip(secondChosenRow.id * 4);
	// Read the contents of the chosen row.
	read(secondChosenRow.contents, 4);
	// Skip the rows after the chosen one.
	skip((4 - secondChosenRow.id - 1) * 4);
}

/**
 * @brief Solves a single test case.
 *
 * @param output The stringstream to which the output should be written.
 */
void MagicTrick::solveProblem(std::stringstream& output)
{
	size_t totalNumberOfMatches = 0;
	size_t chosenNumber = 0;
	bool foundChosenNumber = false;

	// Iterate over the cards in the first chosen row.
	for (size_t i = 0; i < 4; ++i)
	{
		size_t numberOfMatchesInRow = 0;

		// Iterate over the cards in the second chosen row.
		for (size_t j = 0; j < 4; ++j)
		{
			// If the cards match, increment the number of matches.
			if (firstChosenRow.contents[i] == secondChosenRow.contents[j])
			{
				++numberOfMatchesInRow;
			}
		}

		totalNumberOfMatches += numberOfMatchesInRow;

		// If there is exactly one match, we have found the chosen number.
		if (numberOfMatchesInRow == 1)
		{
			chosenNumber = firstChosenRow.contents[i];
			foundChosenNumber = true;
		}
	}

	// If there is more than one match, the magician is a cheater.
	if (totalNumberOfMatches > 1)
	{
		output << "Bad magician!";
	}
	// If there is exactly one match, we have found the chosen number.
	else if (foundChosenNumber)
	{
		output << chosenNumber;
	}
	// If there are no matches, the volunteer is a cheater.
	else
	{
		output << "Volunteer cheated!";
	}
}

} // namespace CodeJam
