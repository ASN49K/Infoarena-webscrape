#include <fstream.h>

using namespace std;

int main ()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b,x;
f>>x;
for (i=1; i=<x;)
{
while (a!=b)
	{
	if (a>b) a=a-b;
	else b=b-a;
	}
g<<a;
}
return 0;
}