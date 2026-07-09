#include<fstream.h>
#include<iostream.h>
long a,b,n;

int main()
{long a,b,n;
	ifstream f("euclid2.in");
ofstream g("euclid2.out ");
	f>>n;
for(int i=0;i<n;i++)
	{f>>a;
	 f>>b;
	
	while(a!=b)
	if(a<b)
			b=b-a;
		else
			a=a-b;
	g<<a<<endl;}
f.close();
g.close();
return 0;
	}
