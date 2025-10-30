#include "Problem.h"
#include <assert.h>
#include <iostream>

namespace CodeJam
{

/**
 * @brief Constructs a new Problem instance.
 *
 * @param inputFilename The name of the input file.
 * @param outputFilename The name of the output file.
 */
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

/**
 * @brief Destroys the Problem instance.
 */
Problem::~Problem()
{
	m_inputFileStream.close();
	m_outputFileStream.flush();
	m_outputFileStream.close();
}

/**
 * @brief Solves all test cases in the input file.
 */
void Problem::solve()
{
	// Solve each test case.
	for (size_t i = 1; i <= m_numberOfCases; ++i)
	{
		// Create a stringstream to hold the output for this test case.
		std::stringstream output;
		output << "Case #" << i << ": ";

		// Read the input for this test case.
		readProblem();

		// Solve this test case.
		solveProblem(output);

		// Add a newline to the end of the output.
		output << std::endl;

		// Write the output to the output file.
		write(output.str());
	}
}

/**
 * @brief Skips a number of values in the input file.
 *
 * @param count The number of values to skip.
 */
void Problem::skip(size_t count)
{
	// Skip the given number of values.
	std::string str;
	for (size_t i = 0; i < count; ++i)
	{
		m_inputFileStream >> str;
	}
}

/**
 * @brief Writes a string to the output file.
 *
 * @param str The string to write.
 */
void Problem::write(const std::string& str)
{
	// Write the given string to standard output and the output file.
	std::cout << str;
	m_outputFileStream << str;
	m_outputFileStream.flush();
}

}
