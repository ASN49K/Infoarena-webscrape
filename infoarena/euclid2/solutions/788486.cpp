#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid()
{
	int a,b;
	f>>a>>b;
	int c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	g<<b<<"\n";
}
int main ()
{
	int n;
	f>>n;
	while(n--)
		euclid();
}