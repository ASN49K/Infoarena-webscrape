#include<iostream.h>
#include<fstream.h>
fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
int t;
int main()
{
	int i,a,b,c;
	f>>t;
	for(i=1;i<=t;i++)
	{	
		f>>a>>b;
		while(b)
		{	
        c=a%b;
        a=b;
        b=c;
		}
		g<<a<<endl;
	}
	return 0;
}