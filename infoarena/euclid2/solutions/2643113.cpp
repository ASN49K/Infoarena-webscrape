#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    unsigned T,i,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> T;
	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		while (b!=0)
			{
			    r=a%b;
			    a=b;
			    b=r;
			}
		g << a << endl;
	}
	return 0;

}
