
#include <fstream>
using namespace std;


int gcd(int x, int y)
{
	int c1 = x, c2 = y;
	while(x != y)
	{
		if(x > y)
			x -= y;
		else
			y -= x;
	}

	return y;
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	int n, a, b;
	in >> n;
	for(int i = 0; i < n; i++)
	{
		in >> a >> b;
		out << gcd(a, b) << endl;
	}

	in.close();
	out.close();
	return 0;
}