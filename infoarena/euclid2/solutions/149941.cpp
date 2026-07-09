#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,x;
int main()
{f>>a>>b;
f.close();
if (a<b) {x=a;a=b;b=x;}
while (b)
	{x=b;
	 b=a%b;
	 a=x;
	 }
x=a;
g<<x;
g.close();
return 0;
}