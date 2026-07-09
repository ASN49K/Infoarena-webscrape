#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
    long a,b,r;
	f>>a>>b;
	while (a%b!=0){r=a%b;
	               a=b;
	               b=r;
			      }
	if (b==1)b=0;
	g<<b;
	return 0;
}