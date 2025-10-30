// https://code.google.com/codejam/contest/2974486/dashboard#s=p0

#ifndef _CODEJAM_MAGICTRICK_H_
#define _CODEJAM_MAGICTRICK_H_

#include "Problem.h"

namespace CodeJam
{

/**
 * @brief Solves the Magic Trick problem.
 *
 * @see https://code.google.com/codejam/contest/2974486/dashboard#s=p0
 */
class MagicTrick : public Problem
{
public:
	/**
	 * @brief Constructs a new MagicTrick instance.
	 *
	 * @param inputFilename The name of the input file.
	 * @param outputFilename The name of the output file.
	 */
	MagicTrick(std::string inputFilename, std::string outputFilename)
		: Problem(inputFilename, outputFilename)
	{}

protected:
	/**
	 * @brief Reads the input for a single test case.
	 */
	virtual void readProblem() override;

	/**
	 * @brief Solves a single test case.
	 *
	 * @param output The stringstream to which the output should be written.
	 */
	virtual void solveProblem(std::stringstream& output) override;

private:
	/**
	 * @brief Represents a row of cards chosen by the magician.
	 */
	struct ChosenRow
	{
		/// The ID of the chosen row.
		size_t id;
		/// The contents of the chosen row.
		size_t contents[4];
	};

	/// The first row chosen by the magician.
	ChosenRow firstChosenRow;
	/// The second row chosen by the magician.
	ChosenRow secondChosenRow;
};

} // namespace CodeJam

#endif // _CODEJAM_MAGICTRICK_H_
