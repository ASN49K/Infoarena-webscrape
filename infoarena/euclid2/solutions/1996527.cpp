#include<fstream>
using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("euclid2.in");
	out.open("euclid2.out");

	unsigned long int T;
	unsigned long long int a, b, r;

	in >> T;

	for (int i = 1; i <= T; i++)
	{
		in >> a >> b;
		while (b != 0)
		{
			r = a%b;
			a = b;
			b = r;
		}
		out << a;
	}
}