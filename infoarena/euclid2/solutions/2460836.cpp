#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int n,int m)
{
	while (n != m)
	{
		if (n > m)
			n = n - m;
		else m = m - n;
	}
	return n;
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