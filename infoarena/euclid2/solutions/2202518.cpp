#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int MyEuclid(int a, int b)
{
	int  r;
	while (b)
	{
		r = a % b; a = b; b = r;
	}
		return  a;
}
int main()
{
	int T, a, b;
	in >> T;
	for (int i = 0; i < T; i++)
	{
		in >> a >> b;
		out << MyEuclid(a, b);
	}
}
