#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int main() {
	int number_of_pairs;

	fin >> number_of_pairs;

	for (int i = 0; i < number_of_pairs; i++)
	{
		int a, b;
		fin >> a >> b;

		while (b)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		fout << a;
	}

	return 0;
}