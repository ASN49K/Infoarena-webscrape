#include<iostream.h>
#include<fstream.h>


int main()
{long n,a,b;
	ifstream f("euclid2.in");
	ofstream h("euclid2.out");
	f>>n;
	for(int i=1;i<=n;i++)
		{f>>a>>b;
	while(a!=b)
		if(a>b)
			a=a-b;
		else
			b=b-a;
		h<<a<<endl;}
	
	
	
	
	return 0;}