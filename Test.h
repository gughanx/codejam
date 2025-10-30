#ifndef _CODEJAM_TEST_H_
#define _CODEJAM_TEST_H_

#include <iostream>
#include <string>
#include <vector>

#define CHECK(x)                                                               \
	if (!(x))                                                                  \
	{                                                                          \
		std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
		return 1;                                                                \
	}

#define RUN_TEST(test)                           \
	{                                              \
		int result = test();                         \
		std::cout << #test << ": "                   \
							<< (result ? "FAILED" : "OK") \
							<< std::endl;                  \
		if (result)                                  \
			return 1;                                  \
	}

namespace CodeJam
{
class Test
{
public:
	static int runTests()
	{
		int result = 0;
		for (auto test : getTests())
		{
			result |= test();
		}
		return result;
	}

	static void addTest(int (*test)())
	{
		getTests().push_back(test);
	}

private:
	static std::vector<int (*)()>& getTests()
	{
		static std::vector<int (*)()> tests;
		return tests;
	}
};
} // namespace CodeJam

#endif // _CODEJAM_TEST_H_
