#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int GCD(int first, int second)
{
	while (second != 0)
	{
		int temp = second;
		second = first % second;
		first = temp;
	}
	return first;
}

int main()
{
	int cases;
	fin >> cases;
	int first, second;
	for (int i = 0; i < cases; i++)
	{
		fin >> first >> second;
		fout << GCD(first, second) << "\n";
		cases -= 1;
	}
}