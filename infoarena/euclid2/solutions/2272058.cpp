#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int cmmdc(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	ll pairs, x, y;
	in >> pairs;
	while (!in.eof())
	{
		in >> x;
		in >> y;
		out << cmmdc(x, y);
		out << "\n";
	}
	int nr, cou;


}




