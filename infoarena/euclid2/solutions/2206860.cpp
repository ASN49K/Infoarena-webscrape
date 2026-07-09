#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void Read(vector <pair <int, int> >& list, int& length)
{
	pair <int, int> prop;

	fin >> length;
	for (int i = 0; i < length; i++)
	{
		fin >> prop.first >> prop.second;
		list.push_back(prop);
	}
}

int GetDivisor(pair <int, int> PairOfNumbers)
{
	int placeHolder;
	while (PairOfNumbers.second)
	{
		placeHolder = PairOfNumbers.first % PairOfNumbers.second;
		PairOfNumbers.first = PairOfNumbers.second;
		PairOfNumbers.second = placeHolder;
	}
	return PairOfNumbers.first;
}

int main()
{
	vector <pair <int, int> > list;
	int length;
	Read(list, length);
	for (int i = 0; i < length; i++)
	{
		fout << GetDivisor(list.at(i)) << '\n';
	}

    return 0;
}

