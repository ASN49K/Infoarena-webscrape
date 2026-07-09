#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y)
{
	if (!y)
		return x;
	else return euclid(y, x%y);
}

int main()
{
	int t, a, b;
	in >> t;
	for (int i = 0; i < t; ++i)
		in >> a >> b,out << euclid(a, b) << endl;
}