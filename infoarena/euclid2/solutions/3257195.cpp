#include <fstream>
#include <iostream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int gcd(int first, int second)
{
	if (second == 0) return first;
	if (first > second)
	{
		return gcd(second, first % second);
	}
	return gcd(first, second % first);
}

int main()
{
	int n;
	int first, second;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> first;
		fin >> second;
		fout << gcd(std::max(first, second), std::min(first, second)) << '\n';
	}
	return 0;
}