#include<iostream.h>
#include<fstream.h>

int cmmdc(int a,int b)
{
int r;
while (b!=0)
{r=a%b;
a=b;
b=r;
}
return a;
}
int main()
{long n,a,b,c;
	ifstream f("euclid2.in");
	ofstream h("euclid2.out");
	f>>n;
	for(int i=1;i<=n;i++)
		{f>>a>>b;
			h<<cmmdc(a,b)<<endl;}
	
	
	
	
	return 0;}