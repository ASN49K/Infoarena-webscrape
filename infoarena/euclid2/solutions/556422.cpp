#include<fstream>
using namespace std;
int x,y,z,t,rest;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>x;
for(y=1;y<=x;y++)
	{f>>z;
	f>>t;
	while(z)
		{rest=t%z;
	t=z;
	z=rest;}
	g<<t<<"\n";}
f.close();
g.close();
return 0;
}
