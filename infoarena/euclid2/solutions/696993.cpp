#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{if (a%b==0)
	return b;
if (b%a==0)
	return a;
if (b>a)
	return euclid(a,b%a);
return euclid (a%b,b);}
int n,a,b,i;
int main(void)
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for (i=1;i<=n;i++)
{f>>a>>b;
g<<euclid(a,b);
g<<'\n';}
f.close();
g.close();
return 0;}
