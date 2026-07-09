#include<iostream>
#include<fstream>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

void Cmmdc_Iterativ()
{
	ifstream fin("fin.in");
	ofstream fout("fout.out");

	int numberOfPair,
		firstNumber,
		secondNumber;

	fin >> numberOfPair;

	for (int i = 0; i < numberOfPair; i++)
	{
		fin >> firstNumber >> secondNumber;

		for (int j = min(firstNumber, secondNumber); j > 0; --j)
		{
			if (firstNumber % j == 0 && secondNumber % j == 0)
			{
				fout << j << "\n";
				break;
			}
		}

	}
}


int main()
{
	Cmmdc_Iterativ();

	return 0;
}