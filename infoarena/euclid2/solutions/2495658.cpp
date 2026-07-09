#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int cmmdc(int a, int b)
{
	if(!b)
		return a;
	else
		return cmmdc(b, a % b);
}

int main()
{
	int a , b;
	f >> a >> b;
	
	int c = cmmdc(a, b);

	if(c == 1)
		g << 0;
	else
		g << c;
}
