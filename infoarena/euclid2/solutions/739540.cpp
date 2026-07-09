#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main ()
{
	int i,t,a,b;
f>>t;
for (i=1;i<=t;i++)
{
	f>>a;
	f>>b;
	while (a!=b)
		if(a>b)
			a=a-b;
		else
			b=b-a;
g<<a<<"\n";
}
return 0;
}
