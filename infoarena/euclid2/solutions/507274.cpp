#include<iostream.h>
#include<fstream.h>


int main()
{long n,a,b,c;
	ifstream f("euclid2.in");
	ofstream h("euclid2.out");
	f>>n;
	for(int i=1;i<=n;i++)
		{f>>a>>b;
	while(b!=0)
	{c=b;
	b=a%b;
	a=c;}
		h<<c<<endl;}
	
	
	
	
	return 0;}