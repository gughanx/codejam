#ifndef _CODEJAM_PROBLEM_H_
#define _CODEJAM_PROBLEM_H_

#include <fstream>
#include <string>
#include <sstream>

namespace CodeJam
{

class Problem
{
public:
	Problem(std::string inputFilename, std::string outputFilename);
	~Problem();
	void solve();

protected:
	size_t m_numberOfCases;

	virtual void readProblem() = 0;
	virtual void solveProblem(std::stringstream& output) = 0;

	// reader functions
	void skip(size_t count);

	template <typename T>
	void read(T& value)
	{
		m_inputFileStream >> value;
	}

	template <typename T>
	void read(T* valueArray, size_t valueArrayLen)
	{
		for (size_t i = 0; i < valueArrayLen; ++i)
		{
			m_inputFileStream >> valueArray[i];
		}
	}

	// writer functions
	void write(const std::string& str);

private:
	std::string m_inputFilename;
	std::string m_outputFilename;

	std::ifstream m_inputFileStream;
	std::ofstream m_outputFileStream;
};

} // namespace CodeJam

#endif // _CODEJAM_PROBLEM_H_