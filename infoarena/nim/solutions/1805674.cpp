#include<fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");



int main()
{
	int T;
	in >> T;

	while (T--)
	{
		int N;
		in >> N;

		int xo=0;

		for (int i = 0;i < N;++i)
		{
			int e;
			in >> e;
			xo ^= e;
		}
		if (xo != 0)
			out << "DA\n";
		else
			out << "NU\n";
	}

	return 0;
}