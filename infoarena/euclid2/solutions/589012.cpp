#include<iostream.h>
#include<fstream.h>
fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
int main()
{
	int a,b,c,t;
	f>>t;
	while(t)
	{	f>>a>>b;
		while(b)
		{	
        c=a%b;
        a=b;
        b=c;
		}
		g<<a<<endl;
		t--;
	}
	return 0;
}