#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return cmmdc(b, a % b);
	}
}

int main(int argc, char * argv[])
{
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open("euclid2.in");
	outFile.open("euclid2.out");

	if (inFile.is_open())
	{
		int nr;
		inFile >> nr;
		if (outFile.is_open())
		{
			for (int i = 0; i < nr; i++)
			{
				int a, b;
				inFile >> a >> b;
				outFile << cmmdc(abs(a), abs(b)) << "\n";
			}
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}