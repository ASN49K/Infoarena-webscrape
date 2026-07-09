#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
/*int a,b,i,n;
int verificare (int a, int b)
{int x,i;
if (a<b)
	{x=a;
	for (i=x;i>=1;i--)
		if (a%i==0&&b%i==0)
			break;
	return i;}
else 
	{x=b;
	for (i=x;i>=1;i--)
		if (a%i==0&&b%i==0)
			break;
	return i;}}
int main ()
{f>>n;
for (i=1;i<=n;i++)
	{f>>a;f>>b;
	g<<verificare(a,b)<<'\n';}
}*/
int i,n,a,b;
int main ()
{f>>n;
for (i=1;i<=n;i++)
	{f>>a;f>>b;
	if (a==0||b==0)
		g<<1<<'\n';
	else 
		{while (a!=b)
			if (a>b)
				a=a-b;
			else b=b-a;
		g<<a<<'\n';}}}