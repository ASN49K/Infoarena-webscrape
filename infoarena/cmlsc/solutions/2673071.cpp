#include <iostream>
#include <vector>
#include <fstream>

std::ifstream infile("cmlsc.in");
std::ofstream outfile("cmlsc.out");

int main()
{
	int l1, l2, c = 0;
	infile >> l1 >> l2;

	std::vector<int> vect1, vect3;

	for (int i = 0; i < l1; i++)
	{
		int num;
		infile >> num;
		vect1.push_back(num);
	}
	for (int i = 0; i < l2; i++)
	{
		int num;
		infile >> num;

		if (std::find(vect1.begin(), vect1.end(), num) != vect1.end())
		{
			vect3.push_back(num);
			c++;
		}
	}

	outfile << c << '\n';
	for (int i = 0; i < c; i++)
	{
		outfile << vect3[i] << ' ';
	}
}