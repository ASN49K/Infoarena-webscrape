#include <fstream>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	int t;
	in >> t;
	
	for(int i = 0;i < t;++i)
	{
		int a, b;
		in >> a >> b;
		out << gcd(a, b) << "\n";
	}
	in.close();
	out.close();
}
	