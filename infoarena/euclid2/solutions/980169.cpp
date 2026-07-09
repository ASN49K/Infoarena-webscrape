#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream in;
	ofstream out;
	int n;
	in.open("euclid2.in");
	out.open("euclid2.out");
	in >> n;

	for(int loop = 0; loop < n; ++loop)
	{
		int a, b;
		in >> a >> b;

		while(b != 0) 
		{
			int t = b;
			b = a % b;
			a = t;
		}

		out << a << '\n';
	}

	in.close();
	out.close();
	return 0;
}