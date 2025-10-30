#include "MagicTrick.h"
#include "Test.h"

#include <fstream>
#include <iostream>
#include <cstdio>

namespace CodeJam
{

// This test should result in "Bad magician!"
int test_bad_magician()
{
	const char* in_file = "test_bad_magician.in";
	const char* out_file = "test_bad_magician.out";

	std::ofstream inputFile(in_file);
	inputFile << "1" << std::endl; // 1 test case
	// Case 1
	inputFile << "1" << std::endl; // Magician is told row 1
	inputFile << "1 2 3 4" << std::endl;
	inputFile << "5 6 7 8" << std::endl;
	inputFile << "9 10 11 12" << std::endl;
	inputFile << "13 14 15 16" << std::endl;
	inputFile << "1" << std::endl; // Magician is told row 1 again
	inputFile << "1 2 5 6" << std::endl; // Second arrangement
	inputFile << "3 4 7 8" << std::endl;
	inputFile << "9 10 11 12" << std::endl;
	inputFile << "13 14 15 16" << std::endl;
	inputFile.close();

	MagicTrick magicTrick(in_file, out_file);
	magicTrick.solve();

	std::ifstream outputFile(out_file);
	std::string output;
	std::getline(outputFile, output);
	outputFile.close();

	CHECK(output == "Case #1: Bad magician!");

	remove(in_file);
	remove(out_file);

	return 0;
}

// This test should result in "Volunteer cheated!"
int test_volunteer_cheated()
{
	const char* in_file = "test_volunteer_cheated.in";
	const char* out_file = "test_volunteer_cheated.out";
	std::ofstream inputFile(in_file);
	inputFile << "1" << std::endl; // 1 test case
	// Case 1
	inputFile << "1" << std::endl; // Magician is told row 1
	inputFile << "1 2 3 4" << std::endl;
	inputFile << "5 6 7 8" << std::endl;
	inputFile << "9 10 11 12" << std::endl;
	inputFile << "13 14 15 16" << std::endl;
	inputFile << "1" << std::endl; // Magician is told row 1 again
	inputFile << "5 6 7 8" << std::endl;   // Second arrangement, row 1 has no common cards
	inputFile << "9 10 11 12" << std::endl;
	inputFile << "13 14 15 16" << std::endl;
	inputFile << "1 2 3 4" << std::endl;
	inputFile.close();

	MagicTrick magicTrick(in_file, out_file);
	magicTrick.solve();

	std::ifstream outputFile(out_file);
	std::string output;
	std::getline(outputFile, output);
	outputFile.close();

	CHECK(output == "Case #1: Volunteer cheated!");

	remove(in_file);
	remove(out_file);

	return 0;
}

// This test should result in the correct card number
int test_ok()
{
	const char* in_file = "test_ok.in";
	const char* out_file = "test_ok.out";
	std::ofstream inputFile(in_file);
	inputFile << "1" << std::endl; // 1 test case
	// Case 1
	inputFile << "2" << std::endl; // Magician is told row 2
	inputFile << "1 2 3 4" << std::endl;
	inputFile << "5 6 7 8" << std::endl;
	inputFile << "9 10 11 12" << std::endl;
	inputFile << "13 14 15 16" << std::endl;
	inputFile << "3" << std::endl; // Magician is told row 3
	inputFile << "1 2 4 5" << std::endl;   // Second arrangement
	inputFile << "3 6 9 10" << std::endl;
	inputFile << "7 11 12 13" << std::endl; // This row contains 7 from the first chosen row
	inputFile << "8 14 15 16" << std::endl;
	inputFile.close();

	MagicTrick magicTrick(in_file, out_file);
	magicTrick.solve();

	std::ifstream outputFile(out_file);
	std::string output;
	std::getline(outputFile, output);
	outputFile.close();

	CHECK(output == "Case #1: 7");

	remove(in_file);
	remove(out_file);

	return 0;
}

void add_tests()
{
	Test::addTest(&test_bad_magician);
	Test::addTest(&test_volunteer_cheated);
	Test::addTest(&test_ok);
}

} // namespace CodeJam

int main()
{
	CodeJam::add_tests();
	return CodeJam::Test::runTests();
}
