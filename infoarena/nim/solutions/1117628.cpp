#include<fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
	int N;
	fin >> N;
	while (N--)
	{
		int x = 0, y, h;
		fin >> h;
		for (int i = 1; i <= h; ++i)
		{
			fin >> y;
			x = x^y;
		}
		if (x)
			fout << "DA\n";
		else
			fout << "NU\n";
	}
	return 0;
}