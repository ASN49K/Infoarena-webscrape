#include<iostream>
#include<fstream>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

void Cmmdc_Iterativ()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

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


void cmmdc_euclid_scadere()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int numberOfPair,
		firstNumber,
		secondNumber,
		iteratorI,
		iteratorJ;

	fin >> numberOfPair;


	for (iteratorI = 0; iteratorI < numberOfPair; ++iteratorI)
	{
		fin >> firstNumber >> secondNumber;

		while (firstNumber != 0 && secondNumber != 0)
		{
			if (firstNumber >= secondNumber)
			{
				firstNumber -= secondNumber;
			}
			else
			{
				secondNumber -= firstNumber;
			}
		}

		firstNumber == 0 ? fout << secondNumber << "\n" : fout << firstNumber << "\n";
	}

}

void cmmdc_Impartire()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int firstNumber,
		secondNumber,
		itrI,
		itrJ,
		numberOfPairs;

	fin >> numberOfPairs;

	while (numberOfPairs != 0)
	{
		fin >> firstNumber >> secondNumber;

		while (firstNumber && secondNumber)
		{
			if (firstNumber >= secondNumber)
			{
				firstNumber %= secondNumber;
			}
			else
			{
				secondNumber %= firstNumber;
			}
		}

		firstNumber == 0 ? fout << secondNumber << "\n" : fout << firstNumber << "\n";
		--numberOfPairs;
	}

}

int main()
{

	cmmdc_Impartire();

	return 0;
}