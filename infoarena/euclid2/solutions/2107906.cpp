#include <fstream>

std::size_t Euclid(std::size_t x, std::size_t y)
{
	if (y == 0)
		return x;

	return Euclid(y, x % y);
}

int main()
{
	std::ifstream inputFile("euclid2.in");
	std::ofstream outputFile("euclid2.out");

	std::size_t sessions;

	inputFile >> sessions;

	std::size_t x, y;

	for (std::size_t i = 0; i < sessions; i++) {
		inputFile >> x >> y;
		outputFile << Euclid(x, y) << "\n";
	}
}