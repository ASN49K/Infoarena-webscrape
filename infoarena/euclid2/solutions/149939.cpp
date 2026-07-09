#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b;
int main()
{f>>a>>b;
f.close();
while (a!=b)
	if (a>b)
		a=a-b;
	else
		b=b-a;
g<<a;
g.close();
return 0;
}