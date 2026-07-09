#include <iostream>
#include <fstream>
using namespace std;

int cmmdc (int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }           
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	unsigned n,a,b;
	f>>n;
	while(n)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
		n--;
	}
	return 0;
}