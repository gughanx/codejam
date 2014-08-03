#include "Problem.h"
#include <assert.h>
#include <iostream>

namespace CodeJam
{

Problem::Problem(std::string inputFilename, std::string outputFilename)
{
	m_inputFilename = inputFilename;
	m_outputFilename = outputFilename;

	m_inputFileStream.open(m_inputFilename);
	assert(m_inputFileStream.is_open());

	m_inputFileStream >> m_numberOfCases;
	assert(m_numberOfCases > 0);

	m_outputFileStream.open(m_outputFilename);
	assert(m_outputFileStream.is_open());
}

Problem::~Problem()
{
	m_inputFileStream.close();
	m_outputFileStream.flush();
	m_outputFileStream.close();
}

void Problem::solve()
{
	for (size_t i = 1; i <= m_numberOfCases; ++i)
	{
		std::stringstream output;
		output << "Case #" << i << ": ";
		readProblem();
		solveProblem(output);
		output << std::endl;
		write(output.str());
	}
}

void Problem::skip(size_t count)
{
	std::string str;
	for (size_t i = 0; i < count; ++i)
	{
		m_inputFileStream >> str;
	}
}

void Problem::write(const std::string& str)
{
	std::cout << str;
	m_outputFileStream << str;
	m_outputFileStream.flush();
}

}