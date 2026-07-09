#include <iostream>
#include <fstream>
using namespace std;
void euclid_CMMDC(int a, int b, int *d)
{
    if (b == 0)
        *d = a;
    else
        euclid_CMMDC(b, a % b, d);
}
int main ()
{
	int a,b,d,T;
	ifstream fi("euclid2.in");
	ofstream fo("euclid2.out");
	fi>>T;
	for (int i=1; i<=T; ++i)
	{
		fi>>a>>b;
		euclid_CMMDC(a,b,&d);
		fo<<d<<"\n";
	}
	return 0;
}