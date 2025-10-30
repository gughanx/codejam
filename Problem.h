#ifndef _CODEJAM_PROBLEM_H_
#define _CODEJAM_PROBLEM_H_

#include <fstream>
#include <string>
#include <sstream>

namespace CodeJam
{

/**
 * @brief Base class for solving a Code Jam problem.
 *
 * This class provides a framework for solving a single Code Jam problem. It
 * handles file I/O and iterating over the test cases. A concrete problem
 * implementation should inherit from this class and implement the readProblem()
 * and solveProblem() methods.
 */
class Problem
{
public:
	/**
	 * @brief Constructs a new Problem instance.
	 *
	 * @param inputFilename The name of the input file.
	 * @param outputFilename The name of the output file.
	 */
	Problem(std::string inputFilename, std::string outputFilename);

	/**
	 * @brief Destroys the Problem instance.
	 */
	~Problem();

	/**
	 * @brief Solves all test cases in the input file.
	 */
	void solve();

protected:
	/// The number of test cases in the input file.
	size_t m_numberOfCases;

	/**
	 * @brief Reads the input for a single test case.
	 *
	 * This method is called once for each test case before solveProblem() is
	 * called.
	 */
	virtual void readProblem() = 0;

	/**
	 * @brief Solves a single test case.
	 *
	 * This method is called once for each test case after readProblem() is
	 * called.
	 *
	 * @param output The stringstream to which the output should be written.
	 */
	virtual void solveProblem(std::stringstream& output) = 0;

	// reader functions
	/**
	 * @brief Skips a number of values in the input file.
	 *
	 * @param count The number of values to skip.
	 */
	void skip(size_t count);

	/**
	 * @brief Reads a single value from the input file.
	 *
	 * @tparam T The type of the value to read.
	 * @param value The variable to which the value should be read.
	 */
	template <typename T>
	void read(T& value)
	{
		m_inputFileStream >> value;
	}

	/**
	 * @brief Reads an array of values from the input file.
	 *
	 * @tparam T The type of the values to read.
	 * @param valueArray The array to which the values should be read.
	 * @param valueArrayLen The number of values to read.
	 */
	template <typename T>
	void read(T* valueArray, size_t valueArrayLen)
	{
		for (size_t i = 0; i < valueArrayLen; ++i)
		{
			m_inputFileStream >> valueArray[i];
		}
	}

	// writer functions
	/**
	 * @brief Writes a string to the output file.
	 *
	 * @param str The string to write.
	 */
	void write(const std::string& str);

private:
	/// The name of the input file.
	std::string m_inputFilename;

	/// The name of the output file.
	std::string m_outputFilename;

	std::ifstream m_inputFileStream;
	std::ofstream m_outputFileStream;
};

} // namespace CodeJam

#endif // _CODEJAM_PROBLEM_H_
