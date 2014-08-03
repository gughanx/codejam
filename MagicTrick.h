// https://code.google.com/codejam/contest/2974486/dashboard#s=p0

#ifndef _CODEJAM_MAGICTRICK_H_
#define _CODEJAM_MAGICTRICK_H_

#include "Problem.h"

namespace CodeJam
{

class MagicTrick : public Problem
{
public:
	MagicTrick(std::string inputFilename, std::string outputFilename)
		: Problem(inputFilename, outputFilename)
	{}

protected:
	virtual void readProblem() override;
	virtual void solveProblem(std::stringstream& output) override;

private:
	struct ChosenRow
	{
		size_t id;
		size_t contents[4];
	};

	ChosenRow firstChosenRow;
	ChosenRow secondChosenRow;
};

} // namespace CodeJam

#endif // _CODEJAM_MAGICTRICK_H_