#include<iostream.h>
#include<fstream.h>

int a,b;

int cmd(int a,int b)
	{
	if(!b)
		return a;
	return cmd(b,a%b);
	}

int main()
	{
	int t,i;	
	fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
	f>>t;
	for(i=1;i<=t;i++)
		{
		f>>a>>b;
		g<<cmd(a,b)<<endl;
		}
	f.close();g.close();
	}