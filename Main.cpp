#include "MagicTrick.h"

/**
 * @brief The main entry point for the program.
 *
 * This function creates a new MagicTrick instance and solves it.
 *
 * @return 0 on success.
 */
int main()
{
	CodeJam::MagicTrick majicTrick("MagicTrick-small.in", "MagicTrick-small.out");
	majicTrick.solve();
}
