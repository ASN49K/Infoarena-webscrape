#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int a,b,t,i,r;
	fstream f("euclid.in",ios::in);
	fstream g("euclid.out",ios::out);
	f>>t;
	if(t<=100000&&t>=1)
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
        }
		g<<a<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
