#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int GCD(int first, int second)
{
	if (first == 0 || second == 0)
		return std::max(first, second);
	return GCD(second, first % second);
}

int main()
{
	int cases;
	fin >> cases;
	int first, second;
	while (cases)
	{
		fin >> first >> second;
		fout << GCD(first, second) << "\n";
		cases -= 1;
	}
}