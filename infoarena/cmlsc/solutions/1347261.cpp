#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	int a,b;
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	f>>a>>b;
	while (a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	g<<b;
	
	return 0;
}