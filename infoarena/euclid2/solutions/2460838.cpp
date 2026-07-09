#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
	int d = 1;
	while (d != 0)
	{
		d = a % b;
		a = b;
		b = d;
	}
	return a;
}
int main()
{
	int t, a, b;
	
	in >> t;
	for (int j = 0; j < t; j++) {
		in >> a >> b;
		out << cmmdc(a, b) << "\n";

	}
	system("pause");
}