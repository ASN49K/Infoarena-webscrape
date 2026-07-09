#include <iostream>
#include <fstream>

using namespace std;
int numar, primulNumar, aldoileaNumar;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
	int rest;
	rest = a%b;
	while (rest > 0)
	{
		a = b;
		b = rest;
		rest = a%b;
	}
	return b;
}

int main()
{
	
	f >> numar;
	for (numar; numar; numar--)
	{
		f >> primulNumar >> aldoileaNumar;
		g << cmmdc(primulNumar, aldoileaNumar) <<'\n';
	}
	f.close();
	g.close();
	return 0;
}