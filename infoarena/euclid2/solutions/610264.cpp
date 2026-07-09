#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	int a,b,i;
	fstream f,g;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	int t;
	f>>t;
	for (i=1;i<=t;i++)
	{
	f>>a>>b;
	while (a!=b)
	{	if (a<b)
			b=b-a;
		if (b<a)
			a=a-b;
	}	
	g<<b;
	}
}