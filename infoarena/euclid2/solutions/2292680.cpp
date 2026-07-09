#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T, a, b, r;
	fin >> T;

	for (int i = 1; i <= T; i++)
	{
		fin >> a >> b;
		if (a != b)
		{
			while (b != 0)
			{
				r = a % b;
				a = b;
				b = r;
			}
			fout << a << endl;
		}
		else fout << a << endl;
	}

	fout.close();

	//system("pause");
	return 0;
}