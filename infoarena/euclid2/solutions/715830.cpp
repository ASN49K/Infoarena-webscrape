#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int a,b,T,i;
	fstream f("euclid.in",ios::in);
	fstream g("euclid.out",ios::out);
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		while(a!=b)
			if(a>b)
				a-=b;
			else
				b-=a;
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}