#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("euclid2.in.txt");
	ofstream fout("euclid2.out.txt");
	int n, a, b, r;
	fin >> n;

	for (int i = 1; i <= n; i++)
	{
		fin >> a >> b;
		while (b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fout << a << endl;
	}

	fout.close();

	//system("pause");
	return 0;
}