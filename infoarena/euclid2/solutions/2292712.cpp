#include <fstream>
using namespace std;

ifstream in("euclid2.in.txt");
ofstream out("euclid2.out.txt");

int func(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int T, a, b;
	in >> T;

	for (int i = 1; i <= T; i++)
	{
		in >> a >> b;
		out << func(a, b) << endl;
	}

	//fout.close();

	//system("pause");
	return 0;
}