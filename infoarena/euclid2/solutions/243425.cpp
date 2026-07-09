#include <fstream>
using namespace std;
int main ()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,x,i;
f>>x;
for (i=1; i=<x;)
{
f>>a>>b;
while (a!=b)
	{
	if (a>b) a=a-b;
	else b=b-a;
	}
g<<a;
}
return 0;
}