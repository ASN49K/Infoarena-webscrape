#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int n1, n2, a;
	fin >> a;
	for (int i = 1; i <= a; i++)
	{
		fin >> n1 >> n2;
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;

		}
		fout << n1 << endl;
	}

	system("pause>nul");
}

